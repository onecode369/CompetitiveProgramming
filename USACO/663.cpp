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
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int minx,maxx,miny,maxy;
    minx = min(x1,x3);
    maxx = max(x2,x4);
    miny = min(y1,y3);
    maxy = max(y2,y4);
    maxx -= minx;
    maxy -= miny;
    maxx = max(maxx,maxy);
    maxx *= maxx;
    cout << maxx;
}

signed main(){
    freopen("square.in","r", stdin );
    freopen("square.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}