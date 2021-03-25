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

    int t;
    string a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int la = a.length()+1;
        int lb = b.length()+1;
        int dp[la][lb];
        for(int i=0;i<la;i++) dp[i][0] = 0;
        for(int i=0;i<lb;i++) dp[0][i] = 0;
        int maxx = 0;
        for(int i=1;i<la;i++){
            for(int j=1;j<lb;j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxx = max(maxx,dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        la--;
        lb--;
        int ans = la+lb;
        ans -= (2*maxx);
        cout << ans << endl;
    }

    return 0;
}