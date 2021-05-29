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
    int n,k;
    cin >> n >> k;
    int arr[1000][1000];
    for(int i=0;i<1000;i++)
    	for(int j=0;j<1000;j++)
    		arr[i][j] = 0;
    int x1,y1,x2,y2;
    while(n--){
    	cin >> x1 >> y1 >> x2 >> y2;
    	arr[x1][y1]++;
    	arr[x1][y2]--;
    	arr[x2][y2]++;
    	arr[x2][y1]--;
    }
    int ans = 0;
    for(int i=0;i<1000;i++){
    	for(int j=0;j<1000;j++){
    		if(i)		arr[i][j] += arr[i-1][j];
    		if(j)		arr[i][j] += arr[i][j-1];
    		if(i && j)	arr[i][j] -= arr[i-1][j-1];
    		if(arr[i][j] == k)	ans++;
    	}
    }
    cout << ans;
}

signed main(){
    freopen("paintbarn.in","r", stdin );
    freopen("paintbarn.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}