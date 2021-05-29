#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void dfs(vector<int>* adjListt, int* visited, int node, int value){
	visited[node] = value;
	for(int x : adjListt[node])
		if(!visited[x])
			dfs(adjListt, visited, x, value);
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> adjListt[n];
    int x,y;
    while(m--){
    	cin >> x >> y;
    	--x;--y;
    	adjListt[x].emplace_back(y);
    	adjListt[y].emplace_back(x);
    }
    int visited[n] = {0};
    x = 1;
    for(int i=0;i<n;i++){
    	if(!visited[i]){
    		dfs(adjListt, visited, i, x);
    		x++;
    	}
    }
    vector<pair<int, int>> nodesColour(n),ans;
    for(int i=1;i<=n;i++)
    	nodesColour[i-1].second = i, nodesColour[i-1].first = visited[i-1];
    sort(nodesColour.begin(), nodesColour.end());
    for(int i=1;i<n;i++){
    	if(nodesColour[i].first != nodesColour[i-1].first){
    		ans.emplace_back(make_pair(nodesColour[i-1].second, nodesColour[i].second));  		
    	}
    }
    cout << (int) ans.size() << endl;
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