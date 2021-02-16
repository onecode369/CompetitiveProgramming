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
        char s[n+1],ans[n+1];
        ans[n] = '\0';
        cin >> s;
        ans[0] = '1';
        for(int i=1;i<n;i++){
            if(s[i] == '0'){
                if(ans[i-1] == '0'){
                    if(s[i-1] == '1') ans[i] = '0';
                    else ans[i] = '1';
                }else{
                    if(s[i-1] == '1') ans[i] = '1';
                    else ans[i] = '0';
                }
            }else{
                if(ans[i-1] == '1'){
                    if(s[i-1] == '1') ans[i] = '0';
                    else ans[i] = '1';
                }else{
                    ans[i] = '1';
                }
            }
        }
        for(int i=0;i<n;i++) cout << ans[i];
        cout << endl;
    }

    return 0;
}