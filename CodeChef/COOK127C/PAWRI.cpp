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
    string s,ans;
    cin >> t;
    while(t--){
        ans = "";
        cin >> s;
        int i=0,l = s.length();
        while(i != l){
            if(i < (l-4)){
                if(s[i] == 'p' && s[i+1] == 'a' && s[i+2] == 'r' && s[i+3] == 't' && s[i+4] == 'y'){
                    ans += "pawri";
                    i += 4;
                }else{
                    ans.push_back(s[i]);
                }
            }else{
                ans.push_back(s[i]);
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}