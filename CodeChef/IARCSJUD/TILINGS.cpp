#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " " << x << endl

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	int dp[n+2] = {0};

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	int s=1;
	for(int i=3;i<=n;i++){
		dp[i] = (dp[i-1] + dp[i-2] + 2*s)%10000;
		s += dp[i-2];
		s %= 10000;
	}

	cout << dp[n] ;
	
	return 0;
}