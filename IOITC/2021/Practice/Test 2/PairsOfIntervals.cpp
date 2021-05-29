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
    vector<tuple<int, int, int, int>> intervals(2*n);
    for(int i=0;i<n;i++){
    	get<2>(intervals[i]) = i;
    	get<3>(intervals[i]) = 1;
    	get<2>(intervals[n+i]) = i;
    	get<3>(intervals[n+i]) = 2;
    	cin >> get<0>(intervals[i]) >> get<1>(intervals[i]) >>
    		   get<0>(intervals[n+i]) >> get<1>(intervals[n+i]);
    }
    sort(intervals.begin(), intervals.end());
    int counted[n]={0};
    
    // if((int) ans.size() == n){
    // 	cout << "Yes" << endl;
    // 	for(int i=0;i<(int) ans.size();i++)
    // 		cout << ans[i] << endl;
    // }else	cout << "No" << endl;
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