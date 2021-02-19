#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n;
    cin >> n;
    long long x = 5LL,sum = 0LL;
    while(5LL <= n){
        sum += (n/5LL);
        n /= x;
    }
    cout << sum;

    return 0;
}