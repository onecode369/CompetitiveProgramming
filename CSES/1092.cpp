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
    if((n*(n+1)) % 4 != 0){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        vector<long long> vec;
        long long sum = 0,x = 0,res = n*(n+1)/4;
        for(long long i=n;i>=1;i--){
            sum += i;
            if(sum <= res){
                vec.push_back(i);
            }else{
                sum -= i;
                if(res-sum > 0){
                    vec.push_back(res-sum);
                    x = res-sum;
                }
                break;
            }
        }
        cout << vec.size() << endl;
        for(int i=0;i<vec.size();i++){
            cout << vec[i] << " ";
        }
        cout << endl << n - vec.size() << endl;
        for(int i=1;i<=n-vec.size();i++){
            if(i != x)
            cout << i << " ";
        }
        if(x != 0) cout << n-vec.size()+1 ;
    }

    return 0;
}