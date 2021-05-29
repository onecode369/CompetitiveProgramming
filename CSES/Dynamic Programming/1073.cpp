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
    vector<int> arr(n);
    deque<int> dp;
    for(int& x : arr)
        cin >> x;
    for(int i=0;i<n;i++){
        int pos = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(pos == (int) dp.size())
            dp.emplace_front(arr[pos]);
        else
            dp[pos] = arr[i];
    }
    cout << (int) dp.size();
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