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
    for(int& x : arr)
    	cin >> x;
    set<int> s;
    int len = (int) s.size();
    for(int i=0;i<(k-1);i++)
    	s.insert(arr[i]);
    len = (int) s.size();
    int j = 0;
    for(int i=k-1;i<n;i++){
    	s.insert(arr[i]);
    	auto it = s.begin();
    	int x = (*it) + k - 1;
    	it = s.end();
    	--it;
    	if((x == (*it)) && ((int) s.size() == k)){
    		cout << (i-k+2) << " " << (i+1);
    		break;
    	}else if((int) s.size() > k){
    		while((int) s.size() > k){
    			s.erase(arr[j]);
    			j++;
    		}
    	}
    }
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