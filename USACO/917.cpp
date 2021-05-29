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
    int a[n],b[n];
    string s[n];
    for(int i=0;i<n;i++)
        cin >> s[i] >> a[i] >> b[i];
    int x = -99999999999, y = 999999999999;
    for(int i=n-1;i>=0;i--){
        if(s[i] == "none"){
            x = max(x, a[i]);
            y = min(y, b[i]);
        }else if(s[i] == "off"){
            x += a[i];
            y += b[i];
        }else{
            x -= b[i];
            y -= a[i];
            x = max(0LL, x);
        }
    }
    cout << x << " " << y << endl;
    x = -999999999999, y = 9999999999999;
    for(int i=0;i<n;i++){
        if(s[i] == "none"){
            x = max(x, a[i]);
            y = min(y, b[i]);
        }else if(s[i] == "off"){
            x -= b[i];
            y -= a[i];
            x = max(0LL, x);
        }else{
            x += a[i];
            y += b[i];
        }
    }
    cout << x << " " << y << endl;
}

signed main(){
    freopen("traffic.in","r", stdin );
    freopen("traffic.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}