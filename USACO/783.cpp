#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

bool covered(int x, int y, int x1, int y1, int x2, int y2){
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;   
    cin >> x3 >> y3 >> x4 >> y4;   
    
    int cornerCover = 0;
    if(covered(x1, y1, x3, y3, x4, y4)) cornerCover++;
    if(covered(x1, y2, x3, y3, x4, y4)) cornerCover++;
    if(covered(x2, y1, x3, y3, x4, y4)) cornerCover++;
    if(covered(x2, y2, x3, y3, x4, y4)) cornerCover++;

    if(cornerCover < 2) {
		cout << (x2-x1)*(y2-y1);
	}else if(cornerCover == 4) {
        cout << 0;
    }else {
        int xL = max(x1, x3);
        int xR = min(x2, x4);
        int yL = max(y1, y3);
        int yR = min(y2, y4);
        cout << (x2-x1)*(y2-y1) - (xR-xL)*(yR-yL);
    }
    return 0;
}