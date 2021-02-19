#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n,m,x,y;
	cin >> n >> m;
	vector<int> adjList[n];
	for(int i=0;i<m;i++){
		cin >> x >> y;
		adjList[x-1].emplace_back(y-1);
		adjList[y-1].emplace_back(x-1);
	}
	int visited[n];
	reset(visited,n,-1);
	x = -1;
	for(int i=0;i<n;i++){
		if(visited[i] == -1){
			x++;
			visited[i] = x;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				for(int node : adjList[q.front()]){
					if(visited[node] == -1){
						q.push(node);
						visited[node] = x;
					}
				}
				q.pop();
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		cin >> x >> y;
		if(visited[--x] == visited[--y]){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}