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
        bool flag = false;
        for(int i=2;i<=sqrt(k);i++){
            if(k%i == 0){
                flag = true;
                break;
            }
        }
        if(!flag && k > n)   cout << "No\n";
        else{
            if((k<=n) || (flag && k <= (n*n)))  cout << "Yes\n";
            else            cout << "No\n";
        }
    }

    return 0;
}