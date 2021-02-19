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

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        char c;
        int arr[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin >> c;
                if(c == '.')    arr[i][j] = 0;
                else            arr[i][j] = 1;
            }

        int cnt1 = 0,cnt2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2 == 0){
                    if(j%2 == 0){
                        if(arr[i][j] == 0)  cnt2++;
                        else                cnt1++;
                    }else{
                        if(arr[i][j] == 1)  cnt2++;
                        else                cnt1++;
                    }
                }else{
                    if(j%2 == 0){
                        if(arr[i][j] == 0)  cnt1++;
                        else                cnt2++;
                    }else{
                        if(arr[i][j] == 1)  cnt1++;
                        else                cnt2++;
                    }
                }
            }
        }
        cout << min(cnt1,cnt2) << endl;
    }
 
    return 0;
}