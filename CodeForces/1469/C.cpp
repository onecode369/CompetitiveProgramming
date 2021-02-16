#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int h[200005],mi[200005],ma[200005];
        for(int i=0;i < n;++i) cin >> h[i];
        mi[0] = ma[0] = h[0];
        if(n == 0 ) cout << "YES\n";
        else{
            int flag = 1;
            for(int i=1;i < n;++i)
            {
                if(!flag) break;
                ma[i] = min(h[i]+k-1, ma[i-1]+k-1);
                mi[i] = max(h[i], mi[i-1]-k+1);
                if(ma[i] < mi[i] || h[i]>ma[i] || h[i]+k-1<mi[i]) flag = 0;
            }
            if(flag && h[n-1]>=mi[n-1] && h[n-1]<=ma[n-1]) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}