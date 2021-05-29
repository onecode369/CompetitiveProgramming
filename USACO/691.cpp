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
    int n;
    cin >> n;
    char arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    int fplay[n+1][3],bplay[n+1][3];
    fplay[0][0] = fplay[0][1] = fplay[0][2] = 0;
    bplay[n][0] = bplay[n][1] = bplay[n][2] = 0;
	for(int i=1;i<=n;i++){
		fplay[i][0] = fplay[i-1][0];
		fplay[i][1] = fplay[i-1][1];
		fplay[i][2] = fplay[i-1][2];
		if(arr[i-1] == 'H')			fplay[i][1]++;
	    else if(arr[i-1] == 'P')	fplay[i][2]++;
		else						fplay[i][0]++;
    }
    for(int i=n-1;i>=0;i--){
    	bplay[i][0] = bplay[i+1][0];
    	bplay[i][1] = bplay[i+1][1];
    	bplay[i][2] = bplay[i+1][2];
	    if(arr[i] == 'H')		bplay[i][1]++;
	    else if(arr[i] == 'P')	bplay[i][2]++;
		else					bplay[i][0]++;
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
		ans = max(ans, fplay[i][0] + max(bplay[i][1], bplay[i][2]));
		ans = max(ans, fplay[i][2] + max(bplay[i][0], bplay[i][1]));
		ans = max(ans, fplay[i][1] + max(bplay[i][0], bplay[i][2]));
	}
	cout << ans;
}

signed main(){
    freopen("hps.in","r", stdin );
    freopen("hps.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}