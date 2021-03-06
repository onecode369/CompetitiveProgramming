#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s[n];
    for(string& x : s)
    	cin >> x;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    	for(int j=0;j<=n;j++)
    		dp[i][j] = 0;
    if(s[0][0] == '.')	dp[1][1] = 1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(s[i-1][j-1] == '*')
    			dp[i][j] = 0;
    		else
    			dp[i][j] += dp[i-1][j]+dp[i][j-1];
    		dp[i][j] %= MOD;
    	}
    }
    cout << dp[n][n];
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