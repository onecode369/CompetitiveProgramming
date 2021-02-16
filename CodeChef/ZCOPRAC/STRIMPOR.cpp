#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cin.tie(0);

    int t,n,k;
    cin >> t;

    while(t--){
    	cin >> n >> k;
    	vector<char> str(n);
    	vector<int> x[3],z[3];
    	for(int i=0;i<n;i++){
    		cin >> str[i];
    		if(i%3 == 0){
    			if(str[i] == 'X'){
    				x[0].push_back(i);
    			}else if(str[i] == 'Z'){
    				z[0].push_back(i);
    			}
    		}else if(i%3 == 1){
    			if(str[i] == 'X'){
    				x[1].push_back(i);
    			}else if(str[i] == 'Z'){
    				z[1].push_back(i);
    			}
    		}else{
    			if(str[i] == 'X'){
    				x[2].push_back(i);
    			}else if(str[i] == 'Z'){
    				z[2].push_back(i);
    			}
    		}
    	}

    }

    return 0;
}