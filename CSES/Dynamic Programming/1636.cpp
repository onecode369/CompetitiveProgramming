#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

vector<int> dp(1000005);

void solve(){
    int n,x;
    cin >> n >> x;
    int coins[n];
    for(int i=0;i<n;i++)
        cin >> coins[i];
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-coins[i] >= 0){
                dp[j] += dp[j-coins[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x];
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}