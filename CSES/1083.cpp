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
    long long sum = (n*(n+1))/2;
    long long rem = 0,x;
    for(int i=0;i<n-1;i++){
        cin >> x;
        rem += x;
    }
    cout << sum-rem;

    return 0;
}