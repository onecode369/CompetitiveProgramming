#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,n,m,k;
    cin >> t;
    while(t--){
    	cin >> n >> m >> k;
        int arr[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> arr[i][j];
        int square = min(n,m);
        int nnpx = n,nnpy = m;
        for(int si=1;si<=square;si++){
            for(int i=0;i<nnpx && i<n-si+1;i++){
                for(int j=0;j<nnpy && j<m-si+1;j++){

                }
            }
        }
    }

    return 0;
}