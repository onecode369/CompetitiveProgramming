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
    string s;
    cin >> s;
    int l = s.length();
    int low,high;
    int start = 0;
    int maxLength = 1;
    for(int i=1;i<l;i++){
        low = i-1;
        high = i;
        while((low>=0) && (high<l) && (s[low]==s[high])){
            if(high - low + 1 > maxLength){
                maxLength = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    for(int i=1;i<l;i++){
        low = i-1;
        high = i+1;
        while((low>=0) && (high<l) && (s[low]==s[high])){
            if(high - low + 1 > maxLength){
                maxLength = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    string ans = s.substr(start,maxLength);
    cout << maxLength << endl << ans << endl;
	
	return 0;
}