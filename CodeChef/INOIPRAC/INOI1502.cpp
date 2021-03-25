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

    long long n,m;
    cin >> n >> m;
    long long pow2[150001];
    pow2[0] = 1;
    for(int i=1;i<150001;i++)
        pow2[i] = (2LL*pow2[i-1])%m;
    vector<long long> fact;
    long long ans = 0;
    if(n == 1)
        ans = 2LL;
    for(int i=n-1;i>0;i--)
        if(n%i == 0){
            bool flag = true;
            for(int j=0;j<fact.size();j++){
                if(fact[j]%i == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += pow2[i];
                ans %= m;
                fact.emplace_back(i);
            }
        }
    ans = pow2[n]-ans;
    ans %= m;
    if(ans < 0) ans += m;
    cout << ans << endl;

    return 0;
}