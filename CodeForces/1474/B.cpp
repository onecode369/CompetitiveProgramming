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

    int t,d;
    cin >> t;
    int prime[100001],num1,num2;    
    reset(prime,100001,1);
    prime[0] = prime[1] = 0;
    for(int i=2;i<=sqrt(100000);i++)
        if(prime[i] == 1)
            for(int j=2*i;j<=100000;j+=i)
                prime[j] = 0;
                
    while(t--){
        cin >> d;
        for(int i=d+1;i<=100000;i++){
            if(prime[i] == 1){
                num1 = i;
                break;
            }
        }
        for(int i=d+num1;i<=100000;i++){
            if(prime[i] == 1){
                num2 = i;
                break;
            }
        }
        cout << num1*num2 << endl;
    }

    return 0;
}