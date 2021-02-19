#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("teleport.in","r",stdin);
    freopen("teleport.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a,b,x,y,temp1,temp2;
    cin >> a >> b >> x >> y;
    temp1 = min(a,b);
    temp2 = max(a,b);
    a = temp1;
    b = temp2;
    temp1 = min(x,y);
    temp2 = max(x,y);
    x = temp1;
    y = temp2;

    cout << min(abs(a-x)+abs(b-y),min(b-a,b+y-a-x));

    return 0;
}