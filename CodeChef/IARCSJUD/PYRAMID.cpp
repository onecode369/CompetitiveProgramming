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

    int n,x,y;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        v.emplace_back(min(x,y));
    }
    sort(v.begin(),v.end());

    int ans = 0;
    for(int i=0;i<n;i++)
        if(v[i] > ans)
            ans++;
    cout << ans << endl;

    return 0;
}