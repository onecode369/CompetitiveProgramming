#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int prime[n+1];
    reset(prime,n+1,1);
    prime[0] = prime[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*2;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }

    vector<pair<int,int>> factor;
    int numFactor=0,x=n;
    for(int i=2;i<=n;i++){
        if(prime[i] && (x%i == 0)){
            numFactor = 0;
            while(x%i == 0){
                numFactor++;
                x /= i;
            }
            factor.emplace_back(make_pair(i,numFactor));
        }
        if(x == 1) break;
    }

    int totient = 1;
    for(int i=0;i<factor.size();i++){
        totient *= (pow(factor[i].first,factor[i].second-1)*(factor[i].first - 1));
    }
    cout << totient;

    return 0;
}