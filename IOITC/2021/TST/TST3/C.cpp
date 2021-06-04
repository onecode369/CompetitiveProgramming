#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) < 1e-9) ? 1 : 0)

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

//////////////////////////////////DEBUG////////////////////////////////////////

#ifdef ONECODE369
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
    
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{\n"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(queue <T> v) {cerr << "[\n"; queue <T> dv = v; while(!dv.empty()) {_print(dv.front()); dv.pop(); cerr << " ";} cerr << "]\n";}
template <class T> void _print(stack <T> v) {cerr << "[\n"; stack <T> dv = v; while(!dv.empty()) {_print(dv.top()  ); dv.pop(); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[\n"; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}

// USACO
void usaco(string file){
    freopen((file + ".in").c_str(),"r", stdin );
    freopen((file + ".out").c_str(),"w",stdout);  
}

ll power(ll a, ll b){
	if(b == 0)	return 1LL;
	ll ans = 1LL;
	if(b % 2 != 0)	ans *= a;
	ll p1 = power(a, b/2);
	ans *= p1;
	ans %= MOD;
	ans *= p1;
	ans %= MOD;
	return ans;
}

ll fact_power(ll n){
	ll ans = 1LL;
	for(int i=1;i<=n;i++){
		ll ans1 = power(i, 2LL * n);
		ans *= ans1;
		ans %= MOD;
	}
	return ans;
}

void solve(){
	int n, m, k;
    cin >> n >> m;
    int a, b;
    
    for(int i=0;i<m;i++){
    	cin >> a >> b;
    }
    k = (n*(n-1))/2;
    k -= m;
}

int main(){
    // usaco("");
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // Google
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}