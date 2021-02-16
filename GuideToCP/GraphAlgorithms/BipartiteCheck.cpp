#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

bool bipartiteCheck(vector<int>* adjList,int* visited,int* color,int node){
    visited[node] = 1;
    for(int x : adjList[node]){
        if(visited[x] == 0){
            color[x] = 1-color[node];
            if(!bipartiteCheck(adjList,visited,color,x)){
                return false;
            }
        }else if(color[node] == color[x]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,e;
    cin >> n >> e;
    int x,y;
    vector<int> adjList[n];
    for(int i=0;i<e;i++){
        cin >> x >> y;
        adjList[x].emplace_back(y);
        adjList[y].emplace_back(x);
    }
    int visited[n],color[n];
    reset(visited,n,0);
    reset(color,n,-1);
    color[0] = 0;
    if(bipartiteCheck(adjList,visited,color,0)){
        cout << "Bipartite Graph\n";
    }else{
        cout << "NonBipartite Graph\n";
    }

    return 0;
}