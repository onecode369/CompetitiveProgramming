#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

long long power(long long a,long long b){
    long long ans = 1LL;
    if(b == 0)  return 1LL;
    if(b%2 == 0){
        long long x = power(a,b/2);
        ans = x*x;
    }else{
        ans = power(a,b-1)*a;
    }
    ans %= MOD;
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long a,b;
    cin >> a >> b;
    cout << power(a,b);

    return 0;
}