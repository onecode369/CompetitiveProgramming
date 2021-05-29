#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
    	set<string> st;
    	for(int j=0;j<n-i+1;j++)
    		st.insert(s.substr(j,i));
    	if((int) st.size() == n-i+1){
    		cout << i;
    		return;
    	}
    }
}

signed main(){
    freopen("whereami.in","r", stdin );
    freopen("whereami.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}