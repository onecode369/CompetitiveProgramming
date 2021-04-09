#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int power(int a,int b){
	if(b == 0)	return 1LL;
	int x = power(a,b/2);
	if(b%2 == 0)
		return (x*x)%MOD;
	else
		return (((x*x)%MOD)*a)%MOD;
}

void solve(){
    int n,x,k;
    cin >> n;
    int numfact=1,sumfact=1,prodfact=1,numfact2=1;
    while(n--){
    	cin >> x >> k;
    	sumfact *= ((power(x,k+1)-1)*power(x-1,MOD-2))%MOD;
    	prodfact = power(prodfact,k+1)*power(power(x,(k*(k+1)/2)),numfact2)%MOD;
		numfact2 = numfact2*(k+1)%(MOD-1);
    	numfact *= (k+1);
    	numfact %= MOD;
    	sumfact %= MOD;
    	prodfact %= MOD;
    }
    cout << numfact << " " << sumfact << " " << prodfact;
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