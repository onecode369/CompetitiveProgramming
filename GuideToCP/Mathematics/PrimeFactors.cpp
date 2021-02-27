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
            for(int j=i*2;j<=n;j += i){
                prime[j] = 0;
            }
        }
    }

    vector<pair<int,int>> factor;
    int numFact=0,x=n;
    for(int i=2;i<=n;i++){
        if(prime[i] && (x%i == 0)){
            numFact = 0;
            while(x%i == 0){
                numFact++;
                x /= i;
            }
            factor.emplace_back(make_pair(i,numFact));
        }
        if(x == 1) break;
    }

    cout << n << " = ";
    for(int i=0;i<factor.size();i++){
        cout << factor[i].first << "^" << factor[i].second;
        if(i != factor.size()-1)    cout << " x ";
    }

    return 0;
}