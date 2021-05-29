#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void dfs(vector<int>* adjList, int* dis, int node){
	if((int) adjList[node].size() == 0){
		dis[node] = 0;
		return;
	}
	int ans = 0;
	for(int i : adjList[node]){
		dfs(adjList, dis, i);
		ans += dis[i];
	}
	ans += (int) adjList[node].size();
	dis[node] = ans;
}

void solve(){
    int n,x;
    cin >> n;
    vector<int> adjList[n];
    for(int i=1;i<n;i++){
    	cin >> x;
    	adjList[x-1].emplace_back(i);
    }
    int dis[n] = {0};
    dfs(adjList, dis, 0);
    for(int i : dis)
    	cout << i << " ";
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