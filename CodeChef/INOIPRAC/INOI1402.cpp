#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    unsigned int n,m,x,y,w;
    cin >> n >> m;
    unsigned int dis[n][n];
    
    memset(dis,127,sizeof(dis));

    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        dis[x-1][y-1] = w;
        dis[y-1][x-1] = w;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<j;k++)
                if(dis[j][k] > dis[j][i] + dis[i][k])
                        dis[j][k] = dis[k][j] = dis[j][i] + dis[i][k];

    unsigned int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            ans = max(ans,dis[i][j]);
    cout << ans;


    return 0;
}