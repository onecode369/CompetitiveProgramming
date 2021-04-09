#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

vector<string> gray_code(int n){
    if(n == 1){
        return {"0","1"};
    }
    vector<string> ans1 = gray_code(n-1);
    vector<string> ans;
    for(int i=0;i< (int) ans1.size();i++)
        ans.emplace_back("0"+ans1[i]);
    for(int i=(int) ans1.size() - 1; i>=0;i--)
        ans.emplace_back("1"+ans1[i]);
    return ans; 
}

void solve(){
    int n;
    cin >> n;
    vector<string> ans = gray_code(n);
    for(string s : ans)
        cout << s << endl;
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}