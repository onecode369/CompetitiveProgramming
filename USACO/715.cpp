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
    int n,k,b,a;
    cin >> n >> k >> b;
    int arr[n] = {0};
    for(int i=0;i<b;i++)
    	cin >> a, arr[a-1] = 1;
    for(int i=1;i<n;i++)
    	arr[i] += arr[i-1];
    int ans = INF;
    for(int i=k-1;i<n;i++)
    	ans = min(ans, arr[i]-arr[i-k+1]);
    cout << ans;
}

signed main(){
    freopen("maxcross.in","r", stdin );
    freopen("maxcross.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}