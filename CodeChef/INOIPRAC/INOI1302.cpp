#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

void dfs(vector<int>* adjList,int* visited,int node){
    visited[node] = 1;
    for(int x : adjList[node])
        if(visited[x] == 0)
            dfs(adjList,visited,x);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,kin;
    cin >> n >> kin;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        int p,x;
        cin >> p;
        for(int j=0;j<p;j++){
            cin >> x;
            v[i].push_back(x);
        }
    }

    vector<int> adjList[n];
    for(int i=0;i<n-1;i++){
        map<int,int> mp;
        for(int j=0;j<v[i].size();j++){
            if(!mp.count(v[i][j])){
                mp[v[i][j]] = 1;
            }
        }
        
        for(int j=i+1;j<n;j++){
            int cnt = 0;
            for(int k=0;k<v[j].size();k++)
                if(mp[v[j][k]] == 1)
                    cnt++;
            if(cnt >= kin){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int visited[n] = {0};
    dfs(adjList,visited,0);

    int cnt = 0;
    for(int i=0;i<n;i++)
        if(visited[i] == 1)
            cnt++;
    cout << cnt;

    return 0;
}