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
    int n,q;
    cin >> n >> q;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    int k = (int) log2(n) + 1;
    int sparse[n][k];
    for(int i=0;i<n;i++)
    	for(int j=0;j<k;j++)
    		sparse[i][j] = -1;
    for(int i=0;i<n;i++)
    	sparse[i][0] = i;
    for(int j=1;j<k;j++)
    	for(int i=0;i+(1LL << j) <= n;i++)
    		sparse[i][j] = (arr[sparse[i][j-1]] < arr[sparse[i+(1LL << (j-1))][j-1]] ? 
    							sparse[i][j-1] : sparse[i+(1LL << (j-1))][j-1]);
    int l,r;
    while(q--){
    	cin >> l >> r;
    	l--;r--;
    	int len = r-l+1;
    	int pow2 = log2(len);
    	int ans = arr[sparse[l][pow2]];
    	ans = min(ans, arr[sparse[r-(1LL << pow2)+1][pow2]]);
    	cout << ans << endl;
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