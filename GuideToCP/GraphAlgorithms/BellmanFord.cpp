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
    int x,y,w;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<e;i++){
        cin >> x >> y >> w;
        edges.emplace_back(make_tuple(x,y,w));
        edges.emplace_back(make_tuple(y,x,w));
    }
    int distance[n];
    reset(distance,n,INF);
    distance[0] = 0;
    for(int i=1;i<n;i++){
        for(auto x : edges){
            int a,b,w;
            tie(a,b,w) = x;
            distance[b] = min(distance[b],distance[a]+w);
        }
    }
    for(int i=0;i<n;i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}