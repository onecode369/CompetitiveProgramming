#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int n;
int coins[105];

int num_ways(int x){
    if(x == 0)
        return 1;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(x-coins[i] >= 0)
            ans += num_ways(x-coins[i]);
        else    break;
    }
    return ans;
}

void solve(){
    int x;
    cin >> n >> x;
    for(int i=0;i<n;i++)
        cin >> coins[i];
    sort(coins,coins+n);
    cout << num_ways(x);
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