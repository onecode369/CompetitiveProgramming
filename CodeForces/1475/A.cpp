#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t,n,p2=1LL;
    cin >> t;
    map<long long,int> mp;
    for(int i=1;i<=55;i++){
        p2 *= 2LL;
        mp[p2] = 1;
    }
    while(t--){
        cin >> n;
        if(mp.count(n)) cout << "NO\n";
        else            cout << "YES\n";
    }

    return 0;
}