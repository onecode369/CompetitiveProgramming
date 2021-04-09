#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

struct point{
	long long x,y;
	void read(){
		cin >> x >> y;
	}
	point operator -(const point b) const{
		return point{b.x-x, b.y-y};
	}
	long long operator *(const point b){
		return (long long) x*b.y - (long long) y*b.x;
	}
};

bool lie_on_segment(point p,point p1,point p2){
	if((p-p1)*(p2-p1) != 0)
		return false;
	return (min(p1.x,p2.x) <= p.x && min(p1.y,p2.y) <= p.y &&
			max(p1.x,p2.x) >= p.x && max(p1.y,p2.y) >= p.y);
}

bool segment_intesection(point p1, point p2, point p3, point p4){
	if((p2-p1)*(p4-p3) == 0){
		for(int i=0;i<2;i++){
			if(max(p1.x,p2.x) < min(p3.x,p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
				return false;			
			}
		}
		swap(p1,p3);
		swap(p2,p4);
		return true;
	}
	for(int i=0;i<2;i++){
		long long sign1 = (p2-p1)*(p3-p1);
		long long sign2 = (p2-p1)*(p4-p1);
		if((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)){
			return false;
		}
		swap(p1,p3);
		swap(p2,p4);
	}
	return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    point p[n];
    for(int i=0;i<n;i++)
    	p[i].read();
    while(m--){
    	point in;
    	in.read();
    	int cnt = 0;
    	bool flag = false;
    	for(int i=0;i<n;i++){
    		int j = (i+1 == n ? 0 : i+1);
    		if(lie_on_segment(in,p[i],p[j])){
    			flag = true;
    			break;
    		}
    		if(segment_intesection(in,point{in.x+1,3000000001},p[i],p[j])){
    			cnt++;
    		}
    	}
    	if(flag){
    		cout << "BOUNDARY\n";
    	}else if(cnt % 2 != 0){
    		cout << "INSIDE\n";
    	}else{
    		cout << "OUTSIDE\n";
    	}
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
    // cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}