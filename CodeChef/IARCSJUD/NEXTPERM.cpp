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

	int n,k;
	cin >> n >> k;
	int arr[n+1];

	while(k--){
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		
		next_permutation(arr,arr+n);

		for(int i=0;i<n;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}