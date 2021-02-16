#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

void connectivityCheck(vector<int>* adjList,int* visited,int node){
    visited[node] = 1;
    for(int x : adjList[node])
        if(visited[x] == 0)
            connectivityCheck(adjList,visited,x);
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
    int visited[n];
    reset(visited,n,0);
    connectivityCheck(adjList,visited,0);
    bool flag = true;
    for(int i=0;i<n;i++)
        if(visited[i] == 0){
            flag = false;
            break;
        }
    if(flag)    cout << "Coonected";
    else        cout << "Not Connected\n";

    return 0;
}