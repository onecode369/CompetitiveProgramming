#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int dfs(vector<int>* adjList, int* visited, int* dis, int node){
	visited[node] = 1;
	if((int) adjList[node].size() == 0)	return 0;
	int ans = 0;
	for(int x : adjList[node]){
		if(visited[x] == 0)
			dis[x] = dfs(adjList, visited, dis, x);
			ans = max(ans, dis[x]);
		visited[x] = 1;
	}
	return ans;
}

void solve(){
    int n,x,y;
    cin >> n;
    vector<int> adjList[n];
    for(int i=1;i<n;i++){
    	cin >> x >> y;
    	x--;
    	y--;
    	adjList[x].emplace_back(y);
    }
    int visited[n],dis[n];
    reset(visited,n,0);
    dis[0] = dfs(adjList, visited, dis, 0);
    for(int& x : dis)
    	cout << x << " ";
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