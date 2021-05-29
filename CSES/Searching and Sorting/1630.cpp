#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool comp(pair<int, int> p1,pair<int, int> p2){
	if(p1.first < p2.first)
		return true;
	else if(p1.first == p2.first)
		return p1.second > p2.second;
	return false;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for(auto& x : tasks)
    	cin >> x.first >> x.second;
    sort(tasks.begin(), tasks.end(), comp);
    int ans = 0LL,t = 0;
    for(auto& x : tasks){
    	t += x.first;
    	ans += (x.second - t);
    }
    cout << ans;
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