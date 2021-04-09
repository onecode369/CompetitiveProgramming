#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

/*
cout << "i\\j\t";
for(int i=1;i<=w;i++)
	cout << i << "\t";
cout << endl;
for(int i=1;i<=l;i++){
	cout << i << "\t";
	for(int j=1;j<=w;j++)
		cout << arr[i][j] << "\t";
	cout << endl;
}
cout << endl;
*/

void solve(){
    int l,w;
    cin >> l >> w;
    int n,k;
    cin >> n >> k;
    int arr[l+1][w+1];
    for(int i=0;i<=l;i++)
    	for(int j=0;j<=w;j++)
    		arr[i][j] = 0;
    int x,y;
    while(n--){
    	cin >> x >> y;
    	arr[x][y]++;
    }
    for(int i=1;i<=l;i++)
    	for(int j=1;j<=w;j++)
    		arr[i][j] += arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
    for(int i=0;i<n;i++){
    	
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