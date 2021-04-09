#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int coins[102];
int dp[1000005];

void solve(){
    int n,x;
    cin >> n >> x;
    for(int i=0;i<n;i++)
    	cin >> coins[i];
    for(int i=1;i<=x;i++)
    	dp[i] = INF;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=x;j++){
    		if(j-coins[i-1] < 0)
    			dp[j] = dp[j];
    		else
    			dp[j] = min(dp[j],dp[j-coins[i-1]]+1);
    	}
    }
    if(dp[x] == INF)
    	cout << "-1";
    else
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