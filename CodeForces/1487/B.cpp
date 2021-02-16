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

    long long t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n%2 == 0){
            if(k%n == 0)    cout << n << endl;
            else            cout << (k%n) << endl;
        }else{
            int x = (n*(n-1))/2;
            k = (k%x);
            if(k%n == 0){
                cout << n-(((2*n)+1-(k%n)-((2*(k-1))/(n-1)))%n)+1 << endl;
            }else{
                cout << n-((n+1-((2*(k-1))/(n-1)))%n)+1 << endl;
            }
        }
    }

    return 0;
}