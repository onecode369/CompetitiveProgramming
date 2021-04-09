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
	void operator -=(point b){
		x -= b.x;
		y -= b.y;
	}
	long long operator *(const point b) const {
		return (long long) x*b.y - (long long) y*b.x;
	}
};

int main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    point p1,p2,p3;
    cin >> t;
    while(t--){
    	p1.read();
    	p2.read();
    	p3.read();
    	p2 -= p1;
    	p3 -= p1;
    	long long cross_product = p2*p3;
    	if(cross_product < 0)		cout << "RIGHT\n";
    	else if(cross_product > 0)	cout << "LEFT\n";
    	else						cout << "TOUCH\n";
    }

    return 0;
}