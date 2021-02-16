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
	int arr[n+1];
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2;i<=n;i++){
		arr[i] = (arr[i-1] + arr[i-2]) % 15746;
	}
	cout << arr[n];
	return 0;
}