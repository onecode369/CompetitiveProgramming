#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool bfs(vector<pair<int, int>>* adjList, int* visited, int n, int node){
	queue<int> q;
	q.push(node);	
	visited[node] = 1;
	while(!q.empty()){
		for(auto x : adjList[q.front()]){
			if(visited[x.first])
				break;
			q.push(x.first);
			visited[x.first] = 1;
		}
		q.pop();
	}
	cout << "OK\n";
	for(int i=0;i<n;i++){
		cout << "OK\n";
		if(visited[i] == 0)
			return false;
	}
	return true;
}

void print_tree(vector<pair<int, int>>* adjList, int* parent, int n, int node){
	int dis[n],color[n],visited[n];
	reset(visited, n , 0);
	reset(dis, n, 0);
	queue<int> q;
	q.push(node);
	vector<int> ans;
	visited[node] = 1;
	while(!q.empty()){
		for(pair<int, int> x : adjList[q.front()]){
			if(visited[x.first])
				break;
			visited[x.first] = 0;
			parent[x.first] = q.front();
			dis[x.first] = dis[q.front()] + 1;
			color[q.front()] = x.second;
			q.push(x.first);
			int y = parent[x.first];
			ans.emplace_back(x.second);
			while(y != -1){
				if(y != node){
					ans.emplace_back(color[y]);
				}
				y = parent[y];
			}
		}
		q.pop();
	}
	cout << (int) ans.size() << " ";
	for(int i=0;i< (int) ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}

void solve(){
    int n, m, k, x, y, c;
    cin >> n >> m >> k;
    vector<pair<int, int>> adjList[n];
    while(m--){
    	cin >> x >> y >> c;
    	adjList[y-1].emplace_back(make_pair(x-1,c));
    }
    int node = -1;
    for(int i=0;i<n;i++){
    	int visited[n] = {0};
    	if(bfs(adjList, visited, n, i)){
    		node = i;
    		break;
    	}
    }
    if(node == -1)
    	cout << "NO\n";
    else{
    	int parent[n];
    	reset(parent, n, -1);
    	cout << "YES\n";
    	print_tree(adjList, parent, n, node);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}