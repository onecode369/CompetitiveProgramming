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
    int e1,e2,weight;
    vector<pair<int,int>> adjList[n];
    for(int i=0;i<e;i++){
        cin >> e1 >> e2 >> weight;
        adjList[e1].emplace_back(make_pair(e2,weight));
        adjList[e2].emplace_back(make_pair(e1,weight));
    }
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    bool processed[n] = {false};
    int distance[n];
    reset(distance,n,INF);
    distance[0] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(processed[u])    continue;
        processed[u] = true;
        for(auto x : adjList[u]){
            int w = x.second,v = x.first;
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                q.push(make_pair(-distance[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}