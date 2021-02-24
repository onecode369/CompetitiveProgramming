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

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int dp[n];
    reset(dp,n,1);
    for(int i=1;i<n;i++){
        for(int j = i-1;j>=0;j--)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j]+1);
    }
    int ans = 1;
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;

    return 0;
}
