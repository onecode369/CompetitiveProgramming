#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr,arr+n,i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n,k;
    cin >> n >> k;
    long long arr[k];
    vector<long long> ar;
    for(int i=0;i<k;i++)
    	cin >> arr[i];
    sort(arr,arr+k,greater<int>());
    for(int i=0;i<k;i++){
    	bool flag = true;
    	for(int j=k-1;j>i;j--)
    		if(arr[i]%arr[j] == 0){
    			flag = false;
    			break;
    		}
    	if(flag) ar.push_back(arr[i]);
    }

    k = ar.size();
    long long ans = n-1,cnt,mul;
    for (int b = 0; b < (1<<k); b++) {
		mul = 1LL;
		cnt = 0;
		for (int i = 0; i < k; i++) {
			if (b&(1<<i)){
				mul *= ar[i];
				cnt++;
				if(mul > n){
					mul = 1LL;
					cnt = 0;
					break;
				}
			}
		}
		if(cnt != 0){
			if(cnt%2 != 0){
				ans -= (n-1)/mul;
			}else{
				ans += (n-1)/mul;
			}
		}
	}
	cout << ans ;

    return 0;
}