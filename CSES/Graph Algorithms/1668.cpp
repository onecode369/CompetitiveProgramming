#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool dfs(vector<int>* adjList, int* visited, int node, int val){
	visited[node] = val;
	for(int x : adjList[node]){
		if(!visited[x]){
			bool ans = dfs(adjList, visited, x, (val == 1) ? 2 : 1);
			if(!ans)	return false;
		}else if(visited[x] == visited[node])	return false;
	}
	return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> adjList[n];
    int x,y;
    while(m--){
    	cin >> x >> y;
    	x--;y--;
    	adjList[x].emplace_back(y);
    	adjList[y].emplace_back(x);
    }
    bool ans = true;
    int visited[n] = {0};
    for(int i=0;i<n;i++){
    	if(!visited[i]){
    		ans = dfs(adjList, visited, i, 1);
    		if(!ans)	break;
    	}
    }
    if(!ans)	cout << "IMPOSSIBLE\n";
    else	for(int x : visited)	cout << x << " ";
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