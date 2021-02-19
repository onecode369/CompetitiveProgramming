#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,e;
    cin >> n >> e;
    int  x,y,w;
    vector<pair<int,int>> adjList[n];
    for(int i=0;i<e;i++){
        cin >> x >> y >> w;
        adjList[x].emplace_back(make_pair(y,w));
        adjList[y].emplace_back(make_pair(x,w));
    }
    int distance[n];
    bool inQueue[n] = {false};
    reset(distance,n,INF);
    distance[0] = 0;
    inQueue[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : adjList[u]){
            int v = x.first;
            int w = x.second;
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                if(!inQueue[v]){
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}