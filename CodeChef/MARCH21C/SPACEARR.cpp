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

    long long t,n;
    cin >> t;
    while(t--){
        cin >> n;
        long long a[n],sum=0,nSum;
        bool flag = false;
        nSum = (n*(n+1LL))/2;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a,a+n);
        for(int i=1;i<=n;i++){
            if(i < a[i-1]){
                flag = true;
                break;
            }
        }
        nSum -= sum;
        if(flag || (nSum % 2 == 0)){
            cout << "Second\n";
        }else{
            cout << "First\n";
        }
    }

    return 0;
}