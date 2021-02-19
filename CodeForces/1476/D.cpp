#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        long long arr[n];
        bool flag = true;
        long long o = 0,num = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]%k != 0){
                if(!(k%2 == 0 && (arr[i]%k == (k/2)))){
                    num++;
                    if(k%4 != 0)  flag = false;
                    else if(!((arr[i]%k) == ((k*1.0)/4)))  flag = false;
                }
            }
            if(arr[i] == 0) o++;
        }
        if(num%2==0) if(o) flag = false;  
        if(flag)    cout << "YES\n";
        else        cout << "NO\n";
    }

    return 0;
}