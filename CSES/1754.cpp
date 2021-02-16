#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    long long a,b;
    while(t--){
        cin >> a >> b;
        if(((a+b)%3 == 0) && (max(a,b) <= 2LL*min(a,b))){
            cout << "YES\n";
        }else   cout << "NO\n";
    }

    return 0;
}