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

    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int ans = 0;
        bool flag = true;
        for(char c : s){
            if(c == '0')    flag = true;
            if(c == '1' && flag){
                ans++;
                flag = false;    
            }
        }
        cout << ans << endl;
    }

    return 0;
}