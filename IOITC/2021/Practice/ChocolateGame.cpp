#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

const int MAXN = 1e7;
vector<int> DP(MAXN+10), LP(MAXN+10);

void solve(){
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for(auto &i : A){
        cin >> i;
        for(int j = 0; j <= MAXN; j += i)
            LP[j] = i;
    }

    int ptr = 0; DP[0] = 0;
    for(int x = 1; x <= MAXN; x++){
        while(ptr+LP[ptr] <= x) ptr++;
        if(ptr >= x) DP[x] = MAXN+10;
        else DP[x] = DP[ptr]+1;
    }

    while(Q--){
        int x; cin >> x;
        if(DP[x] > MAXN) cout << "oo\n";
        else cout << DP[x] << "\n";
    }    
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}