#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

char building[10001][10001];

void rooms(int n, int m, int r, int c){
	if(r ==n || c == m)	return;
	building[r][c] = '*';
	if(building[r+1][c] == '.')				rooms(n, m, r+1, c);
	if(r > 0 && building[r-1][c] == '.')	rooms(n, m, r-1, c);
	if(building[r][c+1] == '.')				rooms(n, m, r, c+1);
	if(c > 0 && building[r][c-1] == '.')	rooms(n, m, r, c-1);
}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin >> building[i][j];
    int x = 1,cnt = 0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(building[i][j] == '.'){
    			cnt++;
    			rooms(n, m, i, j);
    		}
    	}
    }
    cout << cnt;
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}