#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

long long p2[1000001];

long long power2(long long n){
    if(p2[n] != 0)  return p2[n];
    if(n%2 == 0){
        p2[n/2] = power2(n/2);
        p2[n] = p2[n/2]*p2[n/2];
        p2[n] %= MOD; 
    }else{
        p2[(n-1)/2] = power2((n-1)/2);
        p2[(n+1)/2] = power2((n+1)/2);
        p2[n] = p2[(n-1)/2]*p2[(n+1)/2];
        p2[n] %= MOD; 
    }
    return p2[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n;
    cin >> n;
    reset(p2,1000001,0);
    p2[0] = 1LL;
    p2[1] = 2LL;
    cout << power2(n);

    return 0;
}