#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int prime[1000001];

void solve(){
    int n;
    cin >> n;
    map<int,int> div;
    while(n != 1){
    	if(div.count(prime[n]) != 0)
    		div[prime[n]]++;
    	else div[prime[n]] = 1;
    	n /= prime[n];
    }
    int ans = 1;
    for(pair<int,int> x : div)
    	ans *= (x.second+1);
    cout << ans << endl;
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=2;i<=1000000;i++)
    	prime[i] = i;

    prime[1] = 1;
    for(int i=2;i<=1000;i++)
    	if(prime[i] == i)
    		for(int j=i+i;j<=1000000;j+=i)
    			if(prime[j] == j) prime[j] = i;

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}