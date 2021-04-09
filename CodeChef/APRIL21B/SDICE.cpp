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

    int t;
    long long n,ans;
    cin >> t;
    while(t--){
    	cin >> n;
    	ans = (n/4)*44LL;
    	if(n%4 == 0){
    		ans += 16LL;
    	}else if(n%4 == 1){
    		ans += 20LL;
    		if(n > 4)	ans += 12LL;
    	}else if(n%4 == 2){
    		ans += 36LL;
    		if(n > 4)	ans += 8LL;
    	}else{
    		ans += 51LL;
    		if(n > 4)	ans += 4LL;
    	}
    	cout << ans << endl;
    }

    return 0;
}