#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,k,cnt = 0;
    cin >> n >> k;
    while(n--){
        string s;
        cin >> s;
        cnt += s.length();
        if(cnt > k){
            cout << endl << s;
            cnt = s.length();
        }else{
            if(cnt > s.length()){
                cout << " " << s;
            }else{
                cout << s;
            }
        }
    }

    return 0;
}