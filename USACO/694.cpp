#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int minMove(int* dp1,int* dp2,int* dp3,char* t,int k,int i,int n,char c){
    if(i == 0)
        return 0;
    if(c == 'H' && dp1[i] != -1)
        return dp1[i];
    if(c == 'P' && dp2[i] != -1)
        return dp2[i];
    if(c == 'S' && dp3[i] != -1)
        return dp3[i];
    int n1,n2,n3;
    if(c == 'H'){
        n1 = minMove(dp1,dp2,dp3,t,k,i-1,n,'H');
        if(k >= 1){
            n2 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'P');
            n3 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'S');
        }else{
            n2 = minMove(dp1,dp2,dp3,t,k,i-1,n,c);
            n3 = n2;
        }
    }else if(c == 'P'){
        n2 = minMove(dp1,dp2,dp3,t,k,i-1,n,'P');
        if(k >= 1){
            n1 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'H');
            n3 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'S');
        }else{
            n1 = minMove(dp1,dp2,dp3,t,k,i-1,n,c);
            n3 = n1;
        }
    }else if(c == 'S'){
        n3 = minMove(dp1,dp2,dp3,t,k,i-1,n,'S');
        if(k >= 1){
            n1 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'H');
            n2 = minMove(dp1,dp2,dp3,t,k-1,i-1,n,'P');
        }else{
            n1 = minMove(dp1,dp2,dp3,t,k,i-1,n,c);
            n2 = n1;
        }
    }else{
        n1 = minMove(dp1,dp2,dp3,t,k,i,n,'H');
        n2 = minMove(dp1,dp2,dp3,t,k,i,n,'P');
        n3 = minMove(dp1,dp2,dp3,t,k,i,n,'S');
    }
    cout << t[i] << " " << c << " -> " << endl;
    if((t[i] == 'H' && c == 'P') || (t[i] == 'P' && c == 'S') || (t[i] == 'S' && c == 'H')){
        cout << i << " => " << endl;
        n1++;
        n2++;
        n3++;        
    }

    DEBUG(i);
    DEBUG(c);
    DEBUG(t[i]);
    DEBUG(k);
    DEBUG(dp1[i]);
    DEBUG(dp2[i]);
    DEBUG(dp3[i]);

    dp1[i] = max(dp1[i],n1);
    dp2[i] = max(dp2[i],n2);
    dp3[i] = max(dp3[i],n3);

    return max(dp1[i],max(dp2[i],dp3[i]));
}

int main(){
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,k;
    cin >> n >> k;
    char t[n+1];
    for(int i=1;i<=n;i++)
        cin >> t[i];
    int dp1[n+1],dp2[n+1],dp3[n+1];
    reset(dp1,n+1,-1);
    reset(dp2,n+1,-1);
    reset(dp3,n+1,-1);
    int ans = minMove(dp1,dp2,dp3,t,k,n,n,'X');
    cout << ans  << endl;

    for(int i=1;i<=n;i++)   cout << dp1[i] << " ";
    cout << endl;
    for(int i=1;i<=n;i++)   cout << dp2[i] << " ";
    cout << endl;
    for(int i=1;i<=n;i++)   cout << dp3[i] << " ";

    return 0;
}