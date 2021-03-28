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

    int t,n,c;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> n >> c;
        int maxs = ((n+1)*n)/2;
        maxs--;
        if(c > maxs || c < (n-1)){
            cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
        }else{
            int arr[n];
            for(int i=1;i<=n;i++)
                arr[i-1] = i;
            c -= n;
            c++;
            bool flag = true;
            int x = n-1,in=0,fn=n-1;
            while(c != 0){
                if(c >= x){
                    for(int i=fn;i>(in+fn)/2;i--)
                        swap(arr[i],arr[in+fn-i]);
                    c -= x;
                    x--;
                    if(flag){
                        flag = false;
                        fn--;
                    }else{
                        flag = true;
                        in++;
                    }
                }else{
                    fn = in+c;
                    for(int i=fn;i>(in+fn)/2;i--)
                        swap(arr[i],arr[in+fn-i]);
                    c=0;
                }
            }
            cout << "Case #" << tc << ": ";
            for(int an : arr)
                cout << an << " ";
            cout << endl;
        }
    }

    return 0;
}