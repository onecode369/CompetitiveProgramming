#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
	float x1,x2,x3,y1,y2,y3;
    complex<float> p1,p2,p3;
    cin >> t;
    while(t--){
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		p1 = {x1,y1};
		p2 = {x2,y2};
		p3 = {x3,y3};
    	float ans = (conj(p2-p1)*(p3-p2)).imag();
    	if(ans < 0)			cout << "RIGHT\n";
    	else if(ans == 0)	cout << "TOUCH\n";
    	else				cout << "LEFT\n";
    }

    return 0;
}