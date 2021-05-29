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
    int cnt = 0,sum=arr[0],i=0,j=0;
    for(;i<n && j<n;){
    	if(sum <= k){
    		cnt = max(cnt, j-i+1);
    		j++;
    		sum += arr[j];
    	}else{
    		sum -= arr[i];
    		i++;
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