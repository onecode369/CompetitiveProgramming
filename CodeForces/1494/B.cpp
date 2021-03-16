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

    int t,n,U,R,D,L,x;
    cin >> t;
    while(t--){
        cin >> n >> U >> R >> D >> L;
        L1 = L;R1 = R;D1 = D;U1 = U;
        D -= (n-2);
        U -= (n-2);
        L -= (n-2);
        R -= (n-2);
        if(D < 0)   D = 0;
        if(U < 0)   U = 0;
        if(L < 0)   L = 0;
        if(R < 0)   R = 0;
        if(D == 2){
            L1--;
            R1--;
        }
        if(U == 2){
            L1--;
            R1--;
        }
        if(L == 2){
            U1--;
            D1--;
        }
        if(R == 2){
            U1--;
            D1--;
        }
        if(L > 0 && R > 0 && (U+D <= L1+R1))    cout << "YES\n";
        else if 
    }

    return 0;
}