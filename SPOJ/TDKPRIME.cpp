#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

bool prime[90000001];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int> v;
    for(int i=2;i<=sqrt(90000000);i++)
        if(!prime[i]){
            for(int j=i*i;j<=90000000;j+=i)
                prime[j] = true;
        }

    for(int i=2;i<=90000000;i++)
        if(!prime[i])
            v.emplace_back(i);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << v[n-1] << endl;
    }

    return 0;
}