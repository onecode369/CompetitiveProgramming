#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 998244353LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

map<pair<long long,long long>,long long> dp;

long long nCr(long long n, long long r){
       if(n==r) return dp[{n,r}] = 1LL; //Base Case
       if(r==0LL) return dp[{n,r}] = 1LL; //Base Case
       if(r==1LL) return dp[{n,r}] = n;
       if(dp.count(make_pair(n,r))) return dp[{n,r}]; // Using Subproblem Result
       return dp[{n,r}] = (nCr(n-1,r) + nCr(n-1,r-1))%MOD;
} 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    long long arr[n+1],ans[n+1],cntOnes[30];
    reset(ans,n+1,0LL);
    for(long long i=1;i<=n;i++)    cin >> arr[i];
    for(long long i=0;i<30;i++){
        long long cntO = 0LL;
        for(long long j=1;j<=n;j++){
            if((1LL << i) & arr[j]) cntO++;
        }
        cntOnes[i] = cntO;
    }
    long long ans1;
    for(int i=1;i<=n;i++){
        ans1 = 0;
        for(long long j=1;j<=i;j+=2){
            for(long long k=0;k<30;k++){
                if((cntOnes[k] >= j) && ((n-cntOnes[k]) >= (i-j)))
                // ans1 += ((((1LL << k)%MOD) * ((nCr(cntOnes[k],j)*nCr(n-cntOnes[k],(i-j)))%MOD))%MOD);
                ans1 %=  MOD;
            }
        }
        ans[i] = ans1;
        ans[i] += ans[i-1];
        ans[i] %= MOD;
    }
    long long t,x;
    cin >> t;
    while(t--){
        cin >> x;
        cout << ans[x] << endl;
    }

    return 0;
}