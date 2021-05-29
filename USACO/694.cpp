#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    char arr[n];
    for(char& c : arr)
        cin >> c;
    int dp1[n][2],dp2[n][2],dp3[n][2];
    dp1[0][0] = dp2[0][0] = dp3[0][0] = 0;
    dp1[0][1] = dp2[0][1] = dp3[0][1] = k;
    if(arr[0] == 'H')       dp2[0][0] = 1;
    else if(arr[0] == 'P')  dp3[0][0] = 1;
    else                    dp1[0][0] = 1;
    for(int i=1;i<n;i++){
        
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