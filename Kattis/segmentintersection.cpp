#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

struct point{
	int x;
	int y;
};

struct line{
	int a;
	int b;
	int c;
};

int main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    point p[4];
    line l1,l2;
    cin >> n;
    while(n--){
    	cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    	cin >> p[2].x >> p[2].y >> p[3].x >> p[3].y;
    	l1.a = p[1].y-p[0].y;
    	l1.b = p[1].x-p[0].x;
    	l1.c = (2*p[0].x*p[0].y) - (p[0].x*p[1].y) - (p[1].x*p[0].y);
    	int gcd = __gcd(l1.a, __gcd(l1.b, l1.c));
    	l1.a /= gcd;
    	l1.b /= gcd;
    	l1.c /= gcd;
    	l2.a = p[3].y-p[2].y;
    	l2.b = p[3].x-p[2].x;
    	l2.c = (2*p[2].x*p[3].y) - (p[2].x*p[3].y) - (p[3].x*p[2].y);
    	gcd = __gcd(l2.a, __gcd(l2.b, l2.c));
    	l2.a /= gcd;
    	l2.b /= gcd;
    	l2.c /= gcd;
    	if(l1.a*l2.b == l1.b*l2.a){
    		if(l1.c == l2.c){
    			
    		}else{
    			cout << "none" << endl;
    		}
    	}else{

    	}
    }

    return 0;
}