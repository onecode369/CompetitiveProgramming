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
    vector<pair<int,int>> cow(n);
    for(auto& x : cow)
    	cin >> x.second >> x.first;
    sort(cow.begin(), cow.end());
    int sum=0LL,i=0,j=n-1;
    for(;i<=j;){
    	int minnum = min(cow[i].second, cow[j].second);
    	if(i == j) minnum /= 2;
    	cow[i].second -= minnum;
    	cow[j].second -= minnum;
    	sum = max(sum,cow[i].first+cow[j].first);
    	if(cow[i].second == 0)
    		i++;
    	if(cow[j].second == 0)
    		j--;
    }
    cout << sum;
}

signed main(){
    freopen("pairup.in","r", stdin );
    freopen("pairup.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}