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
    int arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
	arr[0] = arr[0]%7;
	for(int i=1;i<n;i++)
		arr[i] = (arr[i]+arr[i-1])%7;
	int minidx[7],maxidx[7];
	reset(minidx,7,50003);
	reset(maxidx,7,-1);
	minidx[0] = -1;
	for(int i=0;i<n;i++){
		minidx[arr[i]] = min(minidx[arr[i]],i);
		maxidx[arr[i]] = max(maxidx[arr[i]],i);
	}
	int ans = -1;
	for(int i=0;i<7;i++)
		ans = max(ans, maxidx[i]-minidx[i]);
	cout << ans;
}

signed main(){
    freopen("div7.in","r", stdin );
    freopen("div7.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}