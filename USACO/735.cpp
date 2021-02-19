#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long x, y;
    cin >> x >> y;

    long long ans = 0;
    long long by = 1;
    long long dir = 1;
    while(true) {
        if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) {
            ans += abs(y-x);
            cout << ans << endl;
            break;
        }else {
            ans += by*2;
            by *= 2;
            dir *= -1;
        }
    }

    return 0;
}