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
    int x,y,m;
    cin >> x >> y >> m;
    int maxx=0;
    for(int i=0;i<=(m/y);i++){
    	int z = (m-(y*i))/x;
    	maxx = max(maxx, x*z + i*y);
    }
    cout << maxx;
}

signed main(){
    freopen("pails.in","r", stdin );
    freopen("pails.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}