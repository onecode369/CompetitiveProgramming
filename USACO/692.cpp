#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " " << x << endl

using namespace std;

string s;
long long n;

char charAt(int k,int total){
	if(k < s.length()){
		return s[k];
	}
	if(k < (s.length()/2)){
		return charAt(k,total/2);
	}else{
		return charAt((k-1)%(total/2),total/2);
	}
}

int main(){
	freopen("cowcode.in","r",stdin);
	freopen("cowcode.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> s >> n;
	long long l = s.length();
	while(l < n){
		l *= 2; 
	}
	cout << charAt(n-1,l);

	return 0;
}