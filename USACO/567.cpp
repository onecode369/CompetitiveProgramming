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
    int a,b,c,d,ans = 0;
    cin >> a >> b >> c >> d;
    ans += (b-a);
    ans += (d-c);
    ans -= max(min(b,d)-max(a,c),0LL);
    cout << ans;
}

signed main(){
    freopen("paint.in","r", stdin );
    freopen("paint.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}