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
    int n,m;
    cin >> n >> m;
    int arr1[n],arr2[m];
    for(int& x : arr1)
    	cin >> x;
    for(int& x : arr2)
    	cin >> x;
    int ans=0;
    if(arr1[0] < arr2[0])
    	ans = arr2[0]-arr1[0];
    if(arr1[n-1] > arr2[m-1])
    	ans = max(ans, arr1[n-1]-arr2[m-1]);
    for(int i=0;i<(m-1);i++){
    	int m = (arr2[i]+arr2[i+1])/2;
    	ans = max(ans, m - arr2[i]);
    	ans = max(ans, arr2[i] - (m+1));
    }
    cout << ans;
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