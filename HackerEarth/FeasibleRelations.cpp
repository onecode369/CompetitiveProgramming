#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t,n,m,x,y;
	string s;
	cin >> t;

	while(t--){
		cin >> n >> m;
		vector<int> adjList[n];
		vector<pair<int,int>> v;
		string s;
		for(int i=0;i<m;i++){
			cin >> x >> s >> y;
			if(s[0] == '='){
				adjList[x-1].emplace_back(y-1);
				adjList[y-1].emplace_back(x-1);
			}else{
				v.emplace_back(make_pair(x-1,y-1));
			}
		}
		x = 1;
		int visited[n];
		reset(visited,n,-1);
		for(int i=0;i<n;i++){
			if(visited[i] == -1){
				queue<int> q;
				q.push(i);
				while(!q.empty()){
					for(int node : adjList[q.front()]){
						if(visited[node] == -1){
							visited[node] = x;
							q.push(node);
						}
					}
					q.pop();
				}
				x++;
			}
		}
		bool flag = true;
		for(int i=0;i<v.size();i++){
			if(visited[v[i].first] == visited[v[i].second]){
				flag = false;
				break;
			}
		}
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}

	return 0;
}