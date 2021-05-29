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
    int n,x;
    cin >> n >> x;
    int arr[n];
    map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    	if(mp.count(arr[i]) == 0)
    		mp[arr[i]] = {i+1,-1};
    	else
    		mp[arr[i]] = {mp[arr[i]].first,i+1};
    }
    for(int i=0;i<n;i++){
    	if(mp.count(x-arr[i]) != 0 && ((arr[i] != (x-arr[i])) || (mp[arr[i]].second != -1))){
    		if(arr[i] == x-arr[i])
	    		cout << mp[arr[i]].first << " " << mp[x-arr[i]].second;
    		else
    			cout << mp[arr[i]].first << " " << mp[x-arr[i]].first;
    		return;
    	}
    }
    cout << "IMPOSSIBLE";
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