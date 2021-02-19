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

    while(n != 1){
        cout << n << " ";
        if(n%2 == 0) n /= 2;
        else         n = n*3LL+1;
    }
    if(n == 1) cout << n;

    return 0;
}