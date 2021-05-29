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
    int n,s,t,b;
    cin >> n;
    int arr[1002] = {0};
    while(n--){
    	cin >> s >> t >> b;
    	arr[s] += b;
    	arr[t+1] -= b;
    }
    for(int i=1;i<=1001;i++)
    	arr[i] += arr[i-1];
    int ans = 0;
    for(int i=0;i<=1001;i++)
    	ans = max(ans, arr[i]);
    cout << ans;
}

signed main(){
    freopen("blist.in","r", stdin );
    freopen("blist.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}