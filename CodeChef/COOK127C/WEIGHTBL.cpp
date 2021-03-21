#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,w1,w2,x1,x2,m;
    cin >> t;
    while(t--){
        cin >> w1 >> w2 >> x1 >> x2 >> m;
        x1 *= m;
        x2 *= m;
        if(w2 >= (w1 + x1) && w2 <= (w1 + x2)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }

    return 0;
}