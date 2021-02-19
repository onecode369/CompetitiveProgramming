#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

long long ans(long long a,long long b){
    if(a == 0)  return 0LL;
    if(a >= b){
        if(b != 1){
            if(((a/b)/b) < (a/(b+1)))
            return ans(a/b,b)+1LL;
            else
            return ans(a,b+1)+1LL;
        }else{
            return  ans(a,b+1)+1LL;
        }
    }else   return 1LL;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << ans(a,b) << endl;
    }

    return 0;
}