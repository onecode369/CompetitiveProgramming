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

    long long t,n,m,k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        long long minn = min(n,m),maxx = max(n,m);
        long long ans = 0;
        for(int i=1;i<minn;i++)
            ans ^= ((k+i+1)*(i%2));
        for(int i=minn;i<=maxx;i++)
            ans ^= ((k+i+1)*(minn%2));
        for(int i=2;i<=minn;i++)
            ans ^= ((k+maxx+i)*((minn-i+1)%2));
        cout << ans << endl;
    }

    return 0;
}