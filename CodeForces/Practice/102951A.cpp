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
    int x[n],y[n];
    for(int i=0;i<n;i++)	cin >> x[i];
    for(int i=0;i<n;i++)	cin >> y[i];
    int maxDis = 0LL;
	for(int i=0;i<(n-1);i++)
		for(int j=i+1;j<n;j++)
			maxDis = max(maxDis, ((y[j]-y[i])*(y[j]-y[i])) + ((x[j]-x[i])*(x[j]-x[i])));
	cout << maxDis;
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