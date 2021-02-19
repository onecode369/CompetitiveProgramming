#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int x5,y5,x6,y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    int sum = 0;
    if(x5<x2 && y5<y2 && x6>x1 && y6>y1){
        sum += ((min(x6,x2)-max(x5,x1))*(min(y6,y2)-max(y5,y1)));
    }
    if(x5<x4 && y5<y4 && x6>x3 && y6>y3){
        sum += ((min(x6,x4)-max(x5,x3))*(min(y6,y4)-max(y5,y3)));
    }
    int ans = ((x2-x1)*(y2-y1)) + ((x4-x3)*(y4-y3));
    cout << ans-sum;

    return 0;
}