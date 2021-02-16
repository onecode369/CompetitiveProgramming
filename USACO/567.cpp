#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if((a > y) || (x > b)){
        cout << (b-a)+(y-x);
    }else{
        if(a <= x){
            cout << (y-a);
        }else{
            cout << (b-x);
        }
    }

    return 0;
}