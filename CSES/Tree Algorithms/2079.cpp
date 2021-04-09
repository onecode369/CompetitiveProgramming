#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

pair<int,int> bfs(vector<int>* adjList, int* parent, int* visited, int n, int node){
	visited[node] = 1;
	parent[node] = -1;
	int len = 1,lastn = node;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		bool flag = false;
		for(int x : adjList[q.front()]){
			if(!visited[x]){
				flag = true;
				visited[x] = 1;
				q.push(x);
				parent[x] = q.front();
			}
		}
		lastn = q.front();
		if(flag)
			len++;
		q.pop();
	}
	return {len,lastn};
}

void solve(){
    int n,a,b;
    cin >> n;
    vector<int> adjList[n];
    for(int i=0;i<(n-1);i++){
    	cin >> a >> b;
    	adjList[a-1].emplace_back(b-1);
    	adjList[b-1].emplace_back(a-1);
    }
    int parent[n];
    int visited[n];
    reset(visited,n,0);
    pair<int,int> centroidinfo = bfs(adjList, parent, visited, n, 0);
    reset(visited,n,0);
    centroidinfo = bfs(adjList, parent, visited, n, centroidinfo.second);
    int ans = centroidinfo.second;
    for(int i=0;i<(centroidinfo.first + 1)/2;i++){
    	ans = parent[ans];
    }
    ans++;
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