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
	point operator -(const point b) const{
		return point{b.x-x, b.y-y};
	}
	void operator -=(const point b){
		x -= b.x;
		y -= b.y;
	}
	long long operator *(const point b) const{
		return (long long) x*b.y - (long long) y*b.x;
	}
};

void solve(){
	point p1,p2,p3,p4;
	p1.read();    
	p2.read();    
	p3.read();
	p4.read();
	if((p2-p1)*(p4-p3) == 0){
		if((p2-p1)*(p3-p1) != 0){
			cout << "NO\n";
			return;
		}
		for(int i=0;i<2;i++){
			if(max(p1.x, p2.x) < min(p3.x,p4.x) || max(p1.y, p2.y) < min(p3.y,p4.y)){
				cout << "NO\n";
				return;
			}
			swap(p1,p3);
			swap(p2,p4);
		}
		cout << "YES\n";
		return;
	}
	for(int i=0;i<2;i++){
		long long sign1 = (p2-p1)*(p3-p1);
		long long sign2 = (p2-p1)*(p4-p1);
		if((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)){
			cout << "NO\n";
			return;
		}
		swap(p1,p3);
		swap(p2,p4);
	}
	cout << "YES\n";
	return;
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
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}