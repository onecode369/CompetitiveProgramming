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
    for(int i=1;i<=t;i++){
        cin >> n;
        int arr[n];
        for(int j=0;j<n;j++)
            cin >> arr[j];
        int cnt = 0,pos=-1,minn = INF;
        for(int j=0;j<n-1;j++){
            minn = INF;
            pos = j;
            for(int k=j;k<n;k++){
                if(arr[k] < minn){
                    minn = arr[k];
                    pos = k;
                }
            }
            cnt += (pos-j+1);
            for(int k=j;k<=((j+pos)/2);k++){
                swap(arr[k],arr[pos-(k-j)]);
            }
        }
        cout << "Case #" << i <<    ": " << cnt << endl;
    }

    return 0;
}