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
	vector<pair<int,int>> game(n);

	for(int i=0;i<n;i++){
		cin >> game[i].second >> game[i].first;
		game[i].first++;	
		game[i].first += game[i].second;
	}
	sort(game.begin(), game.end());

	int end = game[0].first,cnt=1;
	for(int i=1;i<n;i++){
		if(game[i].second >= end){
			cnt++;
			end = game[i].first;
		}
	}
	cout << cnt << endl;
	
	return 0;
}