#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long  n,i,k;
	cin >> n >> k;
	long long a[n+1];
	for(i=1;i<=n;i++)
	    cin >> a[i];
    long long dp1[n+1],dp2[n+1];
    dp1[1]=a[1];
    dp1[2]=a[1]+a[2];
    for(i=3;i<=n;i++)
        dp1[i]=a[i]+max(dp1[i-1],dp1[i-2]);
    dp2[k]=0;
    dp2[k-1]=0;
    for(i=k+1;i<=n;i++)
        dp2[i]=a[i]+max(dp2[i-1],dp2[i-2]);
    long long ans = dp1[k]+dp2[k]-a[k];
    for(i=k;i<=n;i++)
        ans = max(ans,dp1[i]+dp2[i]-a[i]);
    cout<<ans<<endl; 

    return 0;
}