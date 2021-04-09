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
    int m,n;
    cin >> m >> n;
    int arr[n][2];
    for(int i=0;i<n;i++)
    	cin >> arr[i][0] >> arr[i][1];
    int dis = (m/n),ans = 0;
    for(int i=arr[0][0];i<=arr[0][1];i++){
    	int x=i,y=i,minsep=-1;
    	for(int j=1;j<n;j++){
    		x = y;
    		y = max(x+dis,arr[j][0]);
    		y = min(y,arr[j][1]);
    		if(minsep == -1)	minsep = (y-x);
    		else				minsep = min(minsep,y-x);
    	}
    	ans = max(ans,minsep);
    }
    cout << ans;
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