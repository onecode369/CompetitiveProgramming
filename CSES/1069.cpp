#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    int cnt = 1,ans = 0;
    for(int i=1;i<s.length();i++){
        if(s[i] == s[i-1])  cnt++;
        else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    ans = max(ans,cnt);
    cout << ans;

    return 0;
}