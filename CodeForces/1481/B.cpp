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

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++)    cin >> arr[i];
        int ans = -1;
        for(int i=0;i<(n-1);i++){
            if(arr[i+1] > arr[i]){
                k--;
                arr[i]++;
                if(k <= 0){
                    ans = i+1;
                    break;
                }
                if(i > 1)   i-=2;
                else    i = -1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}