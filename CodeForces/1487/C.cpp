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

    int t,n;
    int a[101];
    cin >> t;
    while(t--){
        cin >> n;
        reset(a,101,0);
        if(n%2 != 0){
            int x = -1;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    cout << ((-1)*x) << " ";
                    x *= -1;
                }
            }
        }else{
            int x = 1;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(j == (n-i-1)){
                        cout << "0 ";
                    }else{
                        cout << x << " ";
                        x = (-1)*x;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}