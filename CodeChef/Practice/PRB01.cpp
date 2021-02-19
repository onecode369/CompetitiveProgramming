#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ans = true;
        if(n <= 1) ans = false;
        else{
            for(int i=2;i<=sqrt(n);i++){
                if(n%i == 0){
                    ans = false;
                    break;
                }
            }
        }
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}