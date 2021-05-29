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
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> horizontal(n),vertical(m);
    for(int i=0;i<n;i++)
    	horizontal[i].second = i+1 , cin >> horizontal[i].first;
    for(int i=0;i<m;i++)
    	vertical[i].first = i+1 , cin >> vertical[i].second;
    sort(horizontal.begin(), horizontal.end());
    int visited[n] = {0};
    vector<int> h1(n),h2(n);
    for(int i=0;i<n;i++){
    	h1[i] = horizontal[i].first;
    	h2[i] = horizontal[i].second;
    }
    int put = 0;
    int visited1[m] = {0};
    for(int i=0;i<m;i++){
    	auto it1 = lower_bound(h1.begin(), h1.end(), vertical[i].first);
    	auto it2 = upper_bound(h2.begin(), h2.end(), vertical[i].second);
    	int x = it1 - h1.begin();
    	int y = it2 - h2.begin();
    	if(x > y)	swap(x, y);
    	bool flag = false;
    	for(int j=x;j<=y;j++){
    		if(horizontal[j].second <= vertical[i].second &&
    		    horizontal[j].first >= vertical[i].first){
    			if(!visited[j]){
    				if(!visited1[i])	put++;
    				visited[j] = put;
    			}
    			flag = true;
    			visited1[i] = 1;
    		}
    	}
    	if(!flag)	put++;
    }
    for(int i=0;i<n;i++)
    	if(!visited[i])	put++;
    cout << put << endl;
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
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}