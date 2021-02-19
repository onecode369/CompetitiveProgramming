#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define MAX 200002
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;
int b[1000000];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,n,q,m;
    cin >> t;
    while(t--){
        cin >> n >> q >> m;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int ans=0;
        reset(b,100001,0);
        map<pair<int,int>,int> mp;
        int l,r;
        while(q--){
            cin >> l >> r;
            --l;--r;
            if(a[l] > m)    continue;
            else if(a[l] <= m && a[r] > m){
                b[a[l]]++;
                b[m+1]--;
            }else if(a[r] <= m){
                b[a[l]]++;
                b[m+1]--;
                mp[{a[l],a[r]}]++;
            }
        }
        int k,p;
        for(auto x : mp){
            k = x.first.first;
            p = x.first.second;
            l = x.second;
            b[p+k] -= l;
            b[p+(2*k)] += l;
            int c = p+(2*k);
            while((c+p) <= m){
                c += p;
                b[c] -= l;
                b[c+k] += l;
                c += k;
            }
        }
        for(int i=1;i<=m;i++){
            b[i] += b[i-1];
            ans = max(ans,b[i]);
        }
        cout << ans << endl;
    }

    return 0;
}