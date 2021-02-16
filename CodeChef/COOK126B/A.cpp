#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,n;
    cin >> t;
    int prime[1000001];
    reset(prime,1000001,1);
    prime[0] = prime[1] = 0;
    for(long long i=2;i<sqrt(1000001);i++){
        if(prime[i] == 1){
            for(long long j=i*i;j<1000001;j+=i){
                prime[j] = 0;
            }
        }
    }
    int dp[1000001] = {0};
    for(int i=3;i<1000001;i++){
        dp[i] = dp[i-1];
        if(prime[i] == 1 && prime[i+2] == 1){
            dp[i] = dp[i-1] + 1;
        }
    }
    while(t--){
        cin >> n;
        cout << dp[n-2] << endl;
    }

    return 0;
}