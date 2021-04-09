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
    int ans[n+8];
    ans[0] = 0LL;ans[1] = 1LL;ans[2] = 2LL;
    ans[3] = 4LL;ans[4] = 8LL;ans[5] = 16LL;
    ans[6] = 32LL;
    for(int i=7;i<=n;i++){
        ans [i] = ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4] + ans[i-5] + ans[i-6];
        ans[i] %= MOD; 
    }
    cout << ans[n] << endl;
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