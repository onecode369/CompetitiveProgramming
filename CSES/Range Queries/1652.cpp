#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    int arr[n+1][n+1];
    string s;
    for(int i=0;i<=n;i++)
    	arr[0][i] = arr[i][0] = 0;
    for(int i=0;i<n;i++){
    	cin >> s;
    	for(int j=0;j<n;j++){
    		if(s[j] == '*')	arr[i+1][j+1] = 1;
    		else			arr[i+1][j+1] = 0;
    		arr[i+1][j+1] += arr[i][j+1]+arr[i+1][j]-arr[i][j];
    	}
    }
    int x1,y1,x2,y2;
    while(q--){
    	cin >> x1 >> y1 >> x2 >> y2;
    	cout << (arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1]) << endl;;
    }
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