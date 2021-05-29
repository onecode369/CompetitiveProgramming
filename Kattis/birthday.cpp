#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void dfs(vector<int>* adjList, int* visited, int node, int x, int y){
	visited[node] = 1;
	for(int i : adjList[node])
		if(!visited[i] && !((x == node && y == i) || (x == i && y == node)))
			dfs(adjList, visited, i, x, y);
}

void solve(){
    int p,c,a,b;
    while(cin >> p >> c){
    	if(p == 0 && c == 0)	return;
    	vector<int> adjList[p];
    	while(c--){
    		cin >> a >> b;
    		adjList[a].emplace_back(b);
    		adjList[b].emplace_back(a);
    	}
    	bool flag = true;
    	for(int repi=0;repi<p;repi++){
	    	for(int x : adjList[repi]){
		    	int visited[p] = {0};
		    	dfs(adjList, visited, 0, repi, x);
		    	for(int i : visited){
		    		if(i == 0){
		    			flag = false;
		    			break;
		    		}
		    	}
		    	if(!flag)	break;
		    }
		    if(!flag)	break;
	    }
    	if(!flag)	cout << "Yes\n";
    	else		cout << "No\n";
    }
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