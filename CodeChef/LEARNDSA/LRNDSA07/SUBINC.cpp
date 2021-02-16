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

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n],cnt=1;
        cin >> arr[0];
        for(int i=1;i<n;i++){
            cin >> arr[i];
            if(arr[i] < arr[i-1])
                cnt++;
        }
        int ans = n;
        if(cnt > 1)
            ans += cnt;
        cout << ans << endl;
    }

    return 0;
}