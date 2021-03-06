#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

vector<int> coins,ready,value;

unsigned int solve(int exchange){
    if(exchange < 0)    return INF;
    if(exchange == 0)   return 0;
    if(ready[exchange]) return value[exchange];
    unsigned int best = INF;
    for(auto c : coins){
        best = min(best,1+solve(exchange-c));
    }
    ready[exchange] = 1;
    value[exchange] = best;
    return best;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numberOfCoins,c;
    cin >> numberOfCoins;
    for(int i=0;i<numberOfCoins;i++){
        cin >> c;
        coins.emplace_back(c);
    }
    int exchange;
    cin >> exchange;
    for(int i=0;i<=exchange;i++){
        ready.emplace_back(0);
        value.emplace_back(0);
    }
    cout << solve(exchange) << endl;

    return 0;
}
