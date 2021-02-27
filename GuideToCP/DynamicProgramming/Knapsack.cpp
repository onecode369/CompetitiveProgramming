#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)
/* Incomplete */
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
    int weight[n],maxK = 0;
    for(int i=0;i<n;i++){
        cin >> weight[i];
        maxK += weight[i];
    }
    
    bool possible[maxK+1][n];
    for(int i=0;i<=maxK;i++)
        for(int j=0;j<n;j++)
            possible[i][j] = false;

    possible[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxK;j++){
            if(j - weight[i-1] >= 0){
                possible[j][i] |= possible[j-weight[i-1]][i-1];
            }
        }
    }
    
    cout << "X\t" ;
    for(int i=1;i<=n;i++)
        cout << weight[i-1] << "\t";
    cout << endl;
    for(int i=0;i<=maxK;i++){
        cout << i << "\t";
        for(int j=0;j<n;j++){
            cout << possible[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
