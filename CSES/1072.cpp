#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n,ans;
    cin >> n;
    for(long long i=1;i<=n;i++){
        ans = (i-1LL)*(i+4LL)*((i*i)-3*i+4);
        cout << ans/2 << endl;
    }

    return 0;
}