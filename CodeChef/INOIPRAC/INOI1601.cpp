#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

void completeTree(vector<pair<int,int>>* adjList,int* visited,int* mindis,int n,int idx){
    visited[idx] = 1;
    int minn = INT_MAX;
    for(auto x : adjList[idx]){
        if(visited[x.first] == 0){
            completeTree(adjList,visited,mindis,n,x.first);
        }
        minn = min(minn,min(mindis[x.first],x.second));
    }
    mindis[idx] = minn;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> adjList[n];
    int a[n],p,idx;
    vector<int> mp[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> p;
        if(p == -1)
            idx = i;
        else
            mp[p-1].push_back(i);
    }

    if(n == 1){
        cout << "0\n";
    }else{
        queue<int> q;
        q.push(idx);
        while(!q.empty()){
            for(int x : mp[q.front()]){
                adjList[q.front()].push_back({x,a[x]});
                q.push(x);
            }
            q.pop();
        }
        
        int visited[n] = {0},mindis[n];
        for(int i=0;i<n;i++)
            mindis[i] = INT_MAX;
        completeTree(adjList,visited,mindis,n,idx);

        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            if(mindis[i] != INF)
                ans = max(ans,a[i]-mindis[i]);
        cout << ans ;

    }

    return 0;
}