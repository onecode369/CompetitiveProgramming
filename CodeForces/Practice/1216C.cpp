#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

struct rectangle{
	int x1,y1,x2,y2;
	void read(){
		cin >> x1 >> y1 >> x2 >> y2;
	}
};

bool cover(rectangle black, rectangle white){
	if(black.x1 <= white.x1 && black.y1 <= white.y1
	&& black.x2 >= white.x2 && black.y2 >= white.y2)
		return true;
	return false;
}

void solve(){
    rectangle white,black1,black2;
    white.read();
    black1.read();
    black2.read();
    if(cover(black1, white) || cover(black2, white)){
    	cout << "NO";
    	return;
    }
    for(int i=0;i<2;i++){
		if(black1.x1 <= white.x1 && black1.x2 >= white.x2
		&& black1.y1 <= white.y1 && black1.y2 >= black2.y1
		&& black2.x1 <= white.x1 && black2.x2 >= white.x2
		&& black2.y1 <= black1.y2 && black2.y2 >= white.y2){
			cout << "NO";
			return;
		}
		if(black1.x1 <= white.x1 && black1.x2 >= black2.x1
		&& black1.y1 <= white.y1 && black1.y2 >= white.y2
		&& black2.x1 <= black1.x2 && black2.x2 >= white.x2
		&& black2.y1 <= white.y1 && black2.y2 >= white.y2){
			cout << "NO";
			return;
		}
		swap(black1, black2);
	}
    cout << "YES";
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