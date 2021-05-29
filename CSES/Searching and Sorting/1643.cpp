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
    int arr[n],maxnum=-1000000000000LL;
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    	maxnum = max(maxnum, arr[i]);
    }
    int lsum[n+1],rsum[n+1];
    lsum[0] = rsum[n] = 0LL;
    for(int i=1;i<=n;i++)
    	lsum[i] = max(0LL, lsum[i-1] + arr[i-1]);
    for(int i=n-1;i>=0;i--)
    	rsum[i] = max(0LL, rsum[i+1] + arr[i]);
    int maxsum = -1000000000LL;
    for(int i=0;i<=n;i++)
    	maxsum = max(maxsum, lsum[i] + rsum[i]);
    if(maxsum == 0)
    	maxsum = maxnum;
    cout << maxsum;
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