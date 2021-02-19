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
	set<string> st;
	string s;

	while(cin >> s){
		char s1[81];
		int j=0;
		for(int i=0;i<s.length();i++){
			if(s[i]-'a' >= 0 && 'z'-s[i] >= 0){
				s1[j++] = s[i];
			}else if(s[i]-'A' >= 0 && 'Z'-s[i] >= 0) {
				s1[j++] = (char)(s[i]+32);
			}else{
				s1[j] = '\0';
				j=0;
				st.insert(s1);
			}
		}
		if(strlen(s1) > 0){
			if(s1[j] != '\0')
				s1[j] = '\0';
			st.insert(s1);
		}
	}

	st.erase("");

	cout << st.size() << endl;

	for(auto x : st){
		cout << x << endl;
	}
	
	return 0;
}