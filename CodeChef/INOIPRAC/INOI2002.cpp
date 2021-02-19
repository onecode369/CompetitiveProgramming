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
        cin >> k >> n;
        long long dp[n+1];
        reset(dp,n+1,0);
        if(k == 1 && n >= 3){
            dp[3] = 1LL;
        }else if(k == 2 && n >= 2){
            dp[2] = 1LL;
            if(n >= 3) dp[3] = 1LL;
        }else if(k == 3){
            dp[1] = 1LL;
            if(n >= 3) dp[3] = 1LL;
            if(n >= 6) dp[6] = 2LL;
            if(n >= 9) dp[9] = 4LL;
        }
        for(int i=1;i<=n;i++){
            if(k == 1 && i>=3){
                dp[i] += dp[i-3];
            }else if(k == 2 && i>= 2){
                dp[i] += dp[i-2];
                if(i >= 3) dp[i] += dp[i-3];
            }else if(k == 3){
                dp[i] += dp[i-1];
                if(i >= 3) dp[i] += dp[i-3];
                if(i >= 6) dp[i] += (2*dp[i-6]);
            }
            dp[i] %= MOD;
        }
        cout << dp[n] << endl;
    }

    return 0;
}

