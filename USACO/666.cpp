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
    int n,q;
    cin >> n >> q;
    int arr[n];
    for(int& x : arr)
    	cin >> x;
    sort(arr,arr+n);
    int x,y;
    while(q--){
    	cin >> x >> y;
    	auto it1 = lower_bound(arr, arr+n, x);
    	auto it2 = upper_bound(arr, arr+n, y);
    	int a = it1 - arr;
    	int b = it2 - arr;
    	cout << (b-a) << endl;
    }
}

signed main(){
    freopen("haybales.in","r", stdin );
    freopen("haybales.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}