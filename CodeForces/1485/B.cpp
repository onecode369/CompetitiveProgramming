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

    int n,q,k;
    cin >> n >> q >> k;
    int arr[n+1],ansr[n+1],ansl[n+1],ans[n+2];
    reset(ans,n+2,0);
    for(int i=1;i<=n;i++)    cin >> arr[i];
    for(int i=1;i<=n && (n != 1);i++){
        if(i == 1)         ansr[i] = arr[i+1]-2;
        else if(i == n)    ansl[i] = k-arr[i-1]-1;
        else{
            ansr[i] = (arr[i+1] - 2);
            ansl[i] = (k - arr[i-1] - 1);
            ans[i] = (arr[i+1] - arr[i-1] -2);
        }
        ans[i] += ans[i-1];
    }
    int l,r;
    while(q--){
        cin >> l >> r;
        if(l == r)  cout << k-1 << endl;
        else        cout << ansr[l] + ansl[r] + (ans[r-1] - ans[l]) << endl;
    }

    return 0;
}