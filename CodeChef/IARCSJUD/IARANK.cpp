#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n,k;
	cin >> n;
	int arr[45001],rank;

	for(int i=0;i<n;i++){
		cin >> k;
		rank = i+1;
		if(i == 0) arr[0] = k;
		for(int j=i-1;j>=0;j--){
			if(arr[j] < k){
				arr[j+1]=arr[j];
				if(j == 0){
					arr[j] = k;
					rank = 1;
				}
			}else{
				arr[j+1] = k;
				rank = j+2;
				break;
			}
		}
		cout << rank << endl;
	}
	
	return 0;
}