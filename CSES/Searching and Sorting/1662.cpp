#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    arr[0] = arr[0]%n;
    for(int i=1;i<n;i++)
    	arr[i] = (arr[i] + arr[i-1] + 1000000*n)%n;
    int numdiv[n] = {0};
    numdiv[0] = 1;
    for(int i=0;i<n;i++)
    	numdiv[arr[i]]++;
    int ans = 0;
    for(int i=0;i<n;i++)
    	ans += (numdiv[i]*(numdiv[i]-1))/2;
    cout << ans;
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}