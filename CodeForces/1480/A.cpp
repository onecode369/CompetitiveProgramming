#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i] == 'a') s[i] = 'b';
                else            s[i] = 'a';
            }else{
                if(s[i] == 'z') s[i] = 'y';
                else            s[i] = 'z';
            }
        }
        cout << s << endl;
    }

    return 0;
}