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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<vector<int>> dp(n+1, vector<int>(101));
    for(int& x : arr)
    	cin >> x;
    for(int i=0;i<=n;i++)
    	for(int j=0;j<=100;j++)
    		dp[i][j] = 0;
    if(arr[0] == 0)	for(int i=0;i<=100;i++)	dp[0][i] = 1;
    dp[0][arr[0]] = 1;
    for(int i=1;i<=n;i++){
    	for(int j=)
    }
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