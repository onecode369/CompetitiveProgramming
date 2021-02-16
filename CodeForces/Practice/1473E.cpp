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

    int n,,m;
    cin >> n >> m;
    vector<pair<int,int>> adjList[n];
    int x,y,w;
    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        adjList[x-1].emplace_back({y-1,w});
        adjList[y-1].emplace_back({x-1,w});
    }
    int dis[n],mindis[n],maxdis[n];
    

    return 0;
}