#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

void bfs(vector<int>* adjList,int* visited,int node){
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        for(int x : adjList[q.front()]){
            if(visited[x] == 0){
                cout << q.front()+1 << " " << x+1 << endl;
                visited[x] = 1;
                q.push(x);
            }
        }
        q.pop();
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,x,y;
    cin >> n >> m;
    vector<int> adjList[n];
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adjList[x-1].emplace_back(y-1);
        adjList[y-1].emplace_back(x-1);
    }

    int idx=-1,noOfEdge = -1;
    for(int i=0;i<n;i++)
        if((int)adjList[i].size() > noOfEdge){
            idx = i;
            noOfEdge = adjList[i].size();
        }

    int visited[n];
    reset(visited,n,0);
    bfs(adjList,visited,idx);

    return 0;
}