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
		return point{b.x-x,b.y-y};
	}
	long long operator *(const point b) const{
		return (long long) x*b.y - (long long) y*b.x;
	}
	bool operator <(const point b) const{
		return make_pair(x,y) < make_pair(b.x,b.y);
	}
};

void solve(){
    int n;
    cin >> n;
    point p[n];
    for(int i=0;i<n;i++)
    	p[i].read();
    sort(p,p+n);
    vector<point> hull;
    int siz = 0;
    for(int r=0;r<2;r++){
    	for(point c : p){
	    	while((int) hull.size() - siz >= 2){
	    		point a = hull.end()[-1];
	    		point b = hull.end()[-2];
	    		if((b-c)*(a-c) <= 0){
	    			break;
	    		}
	    		hull.pop_back();
	    	}
	    	hull.emplace_back(c);
	    }
	    reverse(p,p+n);
	    hull.pop_back();
	    siz = hull.size();
    }
    cout << hull.size() << endl;
    for(point c : hull){
    	cout << c.x << " " << c.y << endl;
    }
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