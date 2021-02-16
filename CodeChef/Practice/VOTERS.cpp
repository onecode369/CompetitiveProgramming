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

	int n1,n2,n3,x;
	cin >> n1 >> n2 >> n3;
	map<int,int> mp;
	set<int> ans;
	
	for(int i=0;i<n1;i++){
		cin >> x;
		mp[x] = 1;
	}
	for(int i=0;i<n2;i++){
		cin >> x;
		if(mp.count(x) != 0){
			ans.insert(x);
			mp[x]++;
		}else{
			mp[x] = 1;
		}
	}
	for(int i=0;i<n3;i++){
		cin >> x;
		if(mp.count(x) != 0){
			ans.insert(x);
			mp[x]++;
		}else{
			mp[x] = 1;
		}
	}

	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << endl;
	}

	return 0;
}