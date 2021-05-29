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
    int arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    sort(arr,arr+n);
    int x=1,cnt=1;
    for(int i=0;i<(n-1);i++){
    	cnt = 1;
    	for(int j=i+1;j<n;j++){
    		if(arr[j]-arr[i] > k)	break;
    		cnt++;
    	}
    	x = max(x,cnt);
    }
    cout << x;
}

signed main(){
    freopen("diamond.in","r", stdin );
    freopen("diamond.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}