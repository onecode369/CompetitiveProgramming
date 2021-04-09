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
    int arr[500000] = {0};
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    int l = ceil(sqrt(n));
    int w = (n+l-1)/l;
    int sqrtDec[l][w];
    int sums[l] = {0};
    for(int i=0;i<l;i++){
    	int sum = 0;
    	for(int j=0;j<w;j++){
    		sqrtDec[i][j] = arr[i*l+j];
    		sum += sqrtDec[i][j];
    	}
    	sums[i] = sum;
    }
    int t,a,b;
    while(q--){
    	cin >> t >> a >> b;
    	a--;
    	if(t == 1){
    		sums[a/l] -= sqrtDec[a/l][a%l];
    		sqrtDec[a/l][a%l] = b;
    		sums[a/l] += b;
    		arr[a] = b;
    	}else{
    		b--;
    		int sum = 0;
    		for(int i=a;i<((a+w-1)/w)*w;i++)
    			sum += arr[i];
    		for(int i=(a+w-1)/w;i<(b+1)/w;i++)
    			sum += sums[i];
    		if((b+1)%w != 0)
	    		for(int i=((b+1)/w)*w;i<=b;i++)
	    			sum += arr[i];
    		cout << sum << endl;
    	}
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