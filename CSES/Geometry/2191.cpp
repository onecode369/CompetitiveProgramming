#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

struct point{
	int x,y;
	void read(){
		cin >> x >> y;
	}
	long long operator *(const point b) const{
		return (long long) x*b.y - (long long) y*b.x;
	}
};

void solve(){
    int n;
    cin >> n;
    point p[n];
    for(int i=0;i<n;i++)
    	p[i].read();
    long long ans = 0LL;
    for(int i=0;i<n;i++){
    	ans += p[i]*p[i+1 == n ? 0 : i+1];
    }
    cout << abs(ans);
}

int main(){
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