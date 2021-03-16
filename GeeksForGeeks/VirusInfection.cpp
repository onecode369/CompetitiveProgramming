#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    int l,end=-1;
    l = s.length();
    int cnt = 0;
    for(int i=0;i<l;i++){
        if(s[i] == '1'){
            int x,y;
            if(end < max(0,i-k))    x = max(0,i-k);
            else                    x = end+1;
            y = min(l-1,i+k);
            end = max(end,y);
            if(y >= x)   cnt += (y-x+1);
        }
    }
    cout << cnt;

    return 0;
}