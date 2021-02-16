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

	int t,n,m,x,y;
	string s;
	cin >> t;

	while(t--){
		cin >> n >> m;
		vector<pair<int,int>> edge;
		vector<int> adjListEql[n],adjListNEql[n];
		for(int i=0;i<m;i++){
			cin >> x >> s >> y;
			if(s == "="){
				adjListEql[x-1].push_back(y-1);
				adjListEql[y-1].push_back(x-1);
			}else{
				adjListNEql[x-1].push_back(y-1);
				adjListNEql[y-1].push_back(x-1);
			}
		}
	}
	
	return 0;
}