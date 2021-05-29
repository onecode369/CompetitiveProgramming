#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void dfs(vector<int>* adjList, int* visited, int node, int val){
	visited[node] = val;
	for(int i : adjList[node])
		if(!visited[i])
			dfs(adjList, visited, i, (val == 1) ? 2 : 1);
}

void solve(){
    int n,x,y;
    cin >> n;
    vector<int> adjList[n];
    for(int i=1;i<n;i++){
    	cin >> x >> y;
    	x--;y--;
    	adjList[x].emplace_back(y);
    	adjList[y].emplace_back(x);
    }
    int visited[n] = {0};
    x = 1;
    dfs(adjList, visited, 0, 1);
    int cnt = 0;
    vector<int> fir,sec;
    for(int i=0;i<n;i++){
    	if(visited[i] == 2)	sec.emplace_back(i);
    	else				fir.emplace_back(i);
    }
    for(int i=0;i<(int) fir.size();i++){
   		cnt += (int) sec.size() - (adjList[fir[i]].size());
   	}
    cout << cnt;
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