#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;  
    cin >> x3 >> y3 >> x4 >> y4;
    int ans;
    ans = max(abs(min(x1,x3)-max(x2,x4)),abs(max(y4,y2)-min(y1,y3)));
    cout << ans*ans;

    return 0;
}