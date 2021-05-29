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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    	mp[arr[i]].emplace_back(i+1);
    }
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		int sum = arr[i] + arr[j];
    		if(mp.count(k-sum) != 0){
    			int x = 0;
    			while(x < (int) mp[k-sum].size() &&  (mp[k-sum][x] == (i+1) || mp[k-sum][x] == (j+1))) x++;
    			if(x != (int) mp[k-sum].size() && (!(mp[k-sum][x] == (i+1) || mp[k-sum][x] == (j+1)))){
    				cout << (i+1) << " " << (j+1) << " " << mp[k-sum][x] << endl;
    				return;
    			}
    		}
    	}
    }
    cout << "IMPOSSIBLE\n";
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