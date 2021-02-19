#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

bool cycleDetection(vector<int>* adjList,int* visited,int* parent,int node){
    visited[node] = 1;
    for(int x : adjList[node]){
        if(visited[x] == 0){
            if(!cycleDetection(adjList,visited,parent,x)){
                cout << "Cycle Detected at " << node << endl;
                return false;
            }
        }else if(x != parent[node]){
            cout << "Cycle Detected at " << x << endl;
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
    int visited[n],parent[n];
    reset(visited,n,0);
    reset(parent,n,INF);
    if(cycleDetection(adjList,visited,parent,0)){
        cout << "No Cycle Detected";
    }

    return 0;
}