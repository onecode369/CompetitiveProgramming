#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int fast_mod_pow(int x, int y, int mod) {
    int res = 1;
    while (y > 0) {
        if ((y & 1) == 1) {
            res = ((long long) res * x) % mod;
        }
        y >>= 1;
        x = ((long long) x * x) % mod;
    }
    return res;
}
 
int inverse_mod(int n, int p) {
    return fast_mod_pow(n, p - 2, p);
}
 
int divide_mod(int a, int b, int mod) {
    return ((long long) a * inverse_mod(b, mod)) % mod; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> R(n);
        int max_sum = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> R[i];
            sum += R[i];
            max_sum = max(max_sum, sum);
        }
        int ans = max_sum;
        sum = 0;
        max_sum = 0;
        int m;
        cin >> m;
        vector<int> B(m);
        for (int i = 0; i < m; i++) {
            cin >> B[i];
            sum += B[i];
            max_sum = max(max_sum, sum);
        }
        ans += max_sum;
        cout << ans << '\n';
    }

    return 0;
}