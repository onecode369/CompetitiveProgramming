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

	int n,x,y;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin >> x >> y;
	    a[i]=abs(x-y);
	}
	sort(a,a+n);
	for(int i=n-1;i>=1;i--){
	    a[i-1]=a[i]-a[i-1];
	    sort(a,a+n);
	}
	cout << a[0] << endl;

	return 0;

	return 0;
}