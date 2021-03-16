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

    long long t,c;
    cin >> t;
    while(t--){
        cin >> c;
        long long a=0LL,b=0LL;
        vector<char> bin;
        while(c != 0){
            if(c%2 == 0){
                bin.emplace_back('0');
            }else{
                bin.emplace_back('1');
            }
            c >>= 1LL;
        }
        long long len = bin.size();
        a = 1LL << (len-1LL);
        for(long long i=len-2;i>=0;i--){
            if(bin[i] == '1'){
                if(a > b){
                    b += (1LL << i);
                }else{
                    a += (1LL << i);
                }
            }else{
                a += (1LL << i);
                b += (1LL << i);
            }
        }
        long long ans = a*b;
        cout << ans << endl;
    }

    return 0;
}