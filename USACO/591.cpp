#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int b1,b2,s1,s2,g1,g2,p1,p2;
    cin >> b1 >> b2 ;
    cin >> s1 >> s2 ;
    cin >> g1 >> g2 ;
    cin >> p1 >> p2 ;

    int s,g,p;
    p = p2-p1;
    g = p+g2-g1;
    s = g+s2-s1;

    cout << s << endl;
    cout << g << endl;
    cout << p << endl;

    return 0;
}