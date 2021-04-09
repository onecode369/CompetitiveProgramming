#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

vector<pair<int,int>> tower_of_hanoi(int n, int l, int m, int r){
	if(n == 1)
		return {make_pair(l,r)};
	vector<pair<int,int>> ans = tower_of_hanoi(n-1, l, r, m);
	ans.emplace_back(make_pair(l,r));
	vector<pair<int,int>> ans1 = tower_of_hanoi(n-1, m, l, r);
	ans.insert(ans.end(), ans1.begin(), ans1.end());
	return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans = tower_of_hanoi(n, 1, 2, 3);
    cout << ans.size() << endl;
    for(auto x : ans)
    	cout << x.first << " " << x.second << endl;
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