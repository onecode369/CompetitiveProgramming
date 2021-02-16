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
    int adjMatrix[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adjMatrix[i][j] = 0;
    for(int i=0;i<e;i++){
        cin >> x >> y >> w;
        adjMatrix[x][y] = w;
        adjMatrix[y][x] = w;
    }
    int dist[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) dist[i][j] = 0;
            else if(adjMatrix[i][j]) dist[i][j] = adjMatrix[i][j];
            else dist[i][j] = 1000000;
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }

    return 0;
}