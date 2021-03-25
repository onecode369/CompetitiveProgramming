#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

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
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        int i=1,j=0,cnt=0;
        for(;i<n;i++){
            if(arr[i] != arr[i-1]){
                swap(i,j);
                if((n-j) >= (j-i)){
                    i = 2*j-i;
                    cnt = i;
                }else{
                    cnt = 2*(n-j)+i;
                    break;
                }
            }
        }
        int ans = n-cnt;
        cout << ans << endl;
    }

    return 0;
}