#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int path[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> path[i][j];
    
    for(int i=0;i<=n;i++){
        path[i][0] = 0;
        path[0][i] = 0;
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            path[i][j] += max(path[i-1][j],path[i][j-1]);

    cout << path[n][n];

    return 0;
}
