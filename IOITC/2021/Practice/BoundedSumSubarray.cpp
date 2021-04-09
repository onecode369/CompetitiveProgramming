#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define nINF INT_MIN
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int n,m;
vector<int> arr,lsum,rsum;
int sum_max(int c){
    for(int i=0;i+c-1<n;i++){
        int sum = lsum[c+i-1]-(i == 0 ? 0LL : lsum[i-1]);
        if(sum+rsum[i+c] <= m)    return i;
    }
    return -1;
}

void solve(){
    cin >> n >> m;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    lsum.resize(n);rsum.resize(n+1);
    lsum[0] = arr[0];
    rsum[n] = 0LL;
    for(int i=1;i<n;i++)
        lsum[i] = lsum[i-1] + arr[i];
    for(int i=n-1;i>=0;i--)
        rsum[i] = min(rsum[i+1]+arr[i],0LL);
    int low = 1,high = n;
    while(low < high){
        int mid = (low + high + 1) / 2;
        if(sum_max(mid) != -1)    low = mid;
        else                      high = mid-1;
    }
    cout << low << " " << sum_max(low)+1 << endl;
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