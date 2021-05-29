#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool dfs(vector<int>* same, vector<int>* diff, int* visited, int node ,int colour){
	visited[node] = colour;
	for(int next : same[node]) {
		if (visited[next] == 3-colour)
			return false;
		if (visited[next] == 0) 
			dfs(same, diff, visited, next, colour);
	}
	for (int next : diff[node]) {
		if (visited[next] == colour)
			return false;
		if (visited[next] == 0)
			dfs(same, diff, visited, next, 3-colour);
	}
	return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> same[n],diff[n];
    char x;
    int y, z;
    while(m--){
    	cin >> x >> y >> z;
    	if(x == 'S'){
    		same[y-1].emplace_back(z-1);
    		same[z-1].emplace_back(y-1);
    	}else{
    		diff[y-1].emplace_back(z-1);
    		diff[z-1].emplace_back(y-1);
    	}
    }
   	int visited[n] = {0};
    bool flag = true;
    int cnt = 0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			flag = dfs(same, diff, visited, i, 1);
			cnt++;
			if(!flag)	break;
		}
	}
    if(!flag){
    	cout << "0";
    	return;
    }
    cout << "1";
    for(int i=0;i<cnt;i++)
    	cout << "0";
}

signed main(){
    freopen("revegetate.in","r", stdin );
    freopen("revegetate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}