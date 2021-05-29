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
    vector<pair<int,int>> movie(n);
    for(auto& x : movie)
    	cin >> x.first >> x.second;
    sort(movie.begin(), movie.end());
    int e = movie[0].second,cnt = 1;
    for(int i=1;i<n;i++){
    	if(movie[i].second < e)
    		e = movie[i].second;
    	else if(e <= movie[i].first){
    		e = movie[i].second;
    		cnt++;
    	}
    }
    cout << cnt;
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