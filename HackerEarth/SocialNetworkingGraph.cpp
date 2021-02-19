#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

vector<int> adjList[1000001];
int n;

int bfs(int node,int d){
    int ans = 0;
    queue<int> q;
    int distance[n],visited[n];
    reset(visited,n,0);
    q.push(node);
    distance[node] = d;
    if(!distance[node]) ans++;
    visited[node] = 1;
    while(!q.empty()){
        for(int x : adjList[q.front()]){
            if(visited[x] == 0){
                visited[x] = 1;
                distance[x] = distance[q.front()]-1;
                if(!distance[x]) ans++;
                q.push(x);
            }
        }
        q.pop();
    }
    return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,q,x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adjList[x-1].emplace_back(y-1);
        adjList[y-1].emplace_back(x-1);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> x >> y;
        --x;
        cout << bfs(x,y) << endl;
    }

    return 0;
}