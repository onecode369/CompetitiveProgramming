#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numberOfCoins,c;
    cin >> numberOfCoins;
    vector<int> coins;
    for(int i=0;i<numberOfCoins;i++){
        cin >> c;
        coins.emplace_back(c);
    }
    int exchange;
    cin >> exchange;
    int value[exchange+1];
    value[0] = 1;
    for(int i=1;i<=exchange;i++){
        value[i] = 0;
        for(int c : coins){
            if(i-c >= 0){
                value[i] += value[i-c];
            }
        }
    }
    cout << value[exchange] << endl;

    return 0;
}
