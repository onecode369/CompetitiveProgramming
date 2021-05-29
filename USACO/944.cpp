#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

vector<pair<int, int>> c;
vector<int> nbrs[100000];
int moonet[100000];
struct BB { int x1, x2, y1, y2; };

void visit(int i, int k, BB &bb){
	moonet[i] = k;
	bb.x1 = min(bb.x1, c[i].first);
	bb.x2 = max(bb.x2, c[i].first);
	bb.y1 = min(bb.y1, c[i].second);
	bb.y2 = max(bb.y2, c[i].second);
	for (int j : nbrs[i]) 
		if (moonet[j]==0) visit(j, k, bb);
}

void solve(){
	int n,m;
	cin >> n >> m;
	pair<int, int> p;
	for (int i=0; i<n; i++) {
		cin >> p.first >> p.second;
		c.push_back (p);
	}
	for (int i=0; i<m; i++) {
		cin >> p.first >> p.second;
		nbrs[p.first-1].push_back(p.second-1);
		nbrs[p.second-1].push_back(p.first-1);
	}
	int K = 0, best = 999999999;
	for (int i=0; i<n; i++)     
		if (moonet[i]==0) {
			BB bb = {999999999,0,999999999,0};
			visit(i, ++K, bb);
			best = min(best, 2*(bb.x2-bb.x1+bb.y2-bb.y1));
		}
	cout << best << "\n";
}

signed main(){
    freopen("fenceplan.in","r", stdin );
    freopen("fenceplan.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}