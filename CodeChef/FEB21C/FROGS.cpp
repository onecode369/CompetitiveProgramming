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
    while(t--){
        cin >> n;
        int rpos[n],pos[n],jump[n];
        for(int i=0;i<n;i++){
            cin >> pos[i];
            rpos[pos[i]-1] = i;
        } 
        for(int i=0;i<n;i++){
            cin >> jump[i];
        }
        int ans = 0,an;
        for(int i=1;i<n;i++){
            if(rpos[i-1] >= rpos[i]){
                an = ceil(((rpos[i-1]-rpos[i]+1)*1.0)/jump[rpos[i]]);
                rpos[i] = rpos[i] + an*jump[rpos[i]];
                ans += an;
            }
        }
        cout << ans << endl;
    }

    return 0;
}