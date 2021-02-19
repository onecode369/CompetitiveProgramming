#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;
long long prime[1000005],num[1000005];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t,x,y;
    reset(prime,1000005,1);
    prime[0] = prime[1] = 0;
    num[0] = num[1] = 0;
    for(long long i=2;i<1000005;i++){
        num[i] = num[i-1];
        if(prime[i] == 1){
            num[i]++;
            for(unsigned long long j=i*i;j<1000005;j+=i)   prime[j] = 0;
        }
    }
    cin >> t;
    while(t--){
        cin >> x >> y;
        if(y >= num[x])   cout << "Chef\n";
        else              cout << "Divyam\n";
    }

    return 0;
}