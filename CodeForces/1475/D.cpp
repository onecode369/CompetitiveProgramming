#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define ll long long

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,n,m,x;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll arr[n];
        vector<ll> ph1,ph2;
        for(int i=0;i<n;i++)    cin >> arr[i];
        for(int i=0;i<n;i++){
            cin >> x;
            if(x == 1)  ph1.emplace_back(arr[i]);
            else        ph2.emplace_back(arr[i]);
        }
        sort(ph1.begin(),ph1.end());
        sort(ph2.begin(),ph2.end());
        int i1 = ph1.size()-1,i2 = ph2.size()-1,mem = 0,ans = 0;
        while(mem < m && i1 >= 0 && i2 >= 0){
            if(mem + ph1[i1] >= m){
                ans++;
                i1--;
            }else if(mem + ph2[i2] >= )
        }
    }

    return 0;
}