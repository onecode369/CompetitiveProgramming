#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, a`rr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    long long x,y;&
    while(t--){
        cin >> x >> y;
        if(x > y){
            if(x%2 == 0)    cout << (x*x)-y+1LL << endl;
            else            cout << (x-1LL)*(x-1LL)+y << endl;
        }else if(y > x){
            if(y%2 == 0)    cout << (y-1LL)*(y-1LL)+x << endl;
            else            cout << (y*y)-x+1LL << endl;
        }else               cout << (x*x)-x+1LL << endl;
    }

    return 0;
}
