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

    long long t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        long long arr[n];
        for(long long i=0;i<n;i++)
            cin >> arr[i];
        if(n <= k){
            long long cnt = 0;
            for(long long i=0;i<n;i++)
                if(arr[i] == 1)
                    cnt++;
            cout << ((cnt*(cnt+1))/2) << endl;
        }else{
            long long x[n-k+1],cnt=0,cnt1=0;
            for(long long i=0;i<k;i++)
                if(arr[i] == 1)
                    cnt++;
            x[0] = cnt;
            cnt1 = cnt;
            for(long long i=k;i<n;i++){
                if(arr[i-k] == 1)   --cnt;
                if(arr[i] == 1){
                    ++cnt;
                    ++cnt1;
                }
                x[i-k+1] = cnt;
            }
            sort(x,x+(n-k+1));
            long long ans = 0;
            ans += ((x[0]*(x[0]+1))/2);
            ans += (cnt1-x[0]);
            cout << ans << endl;
        }
    }

    return 0;
}