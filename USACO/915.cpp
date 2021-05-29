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
    int a,b,c,x,y,z;
    cin >> a >> b >> c;
    x = min(a,min(b,c));
    z = max(a,max(b,c));
    y = a+b+c-x-z;
    if(x+2 == z)
        cout << "0\n";
    else if(x+2 == y || y+2 == z)
        cout << "1\n";
    else
        cout << "2\n";
    cout << (max(b-a, c-b) - 1);
}

signed main(){
    freopen("herding.in","r", stdin );
    freopen("herding.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}