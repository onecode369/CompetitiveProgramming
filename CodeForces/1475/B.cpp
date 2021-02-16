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
    cin >> t;
    while(t--){
        cin >> n;
        int num = 0,x=n;
        while(x%2020 != 0 && x>=2020){
            num++;
            x--;
        }
        if(x%2020 == 0){
            if((x/2020) >= num){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}