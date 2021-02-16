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

    long long t,n;
    cin >> t;
    while(t--){
        cin >> n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        cout << 2LL*(arr[n-1]-arr[0]) << endl;
    }

    return 0;
}