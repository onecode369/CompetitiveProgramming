#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

bool comp(pair<int,int> x, pair<int,int> y){
    return x.second > y.second;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int x,y,z;
    vector<pair<int,int>> tm;
    for(int i=0;i<n;i++){
        cin >> x >> y >> z;
        tm.push_back({y+z,x});
    }
    sort(tm.begin(),tm.end(),greater<pair<int,int>>());
    int ans = 0,sum = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,tm[i].second + tm[i].first + sum);
        sum += tm[i].second;
    }
    cout << ans ;

    return 0;
}
