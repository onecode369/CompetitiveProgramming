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
    string s1,s2;
    cin >> s1 >> s2;
    bool mismatch = false;
    int cnt = 0;
    for(int i=0;i<n;i++){
    	if(s1[i] != s2[i]){
    		if(!mismatch){
    			mismatch = true;
    			cnt++;
    		}
    	}else	mismatch = false;
    }
    cout << cnt;
}

signed main(){
    freopen("breedflip.in","r", stdin );
    freopen("breedflip.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}