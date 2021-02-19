#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n=s.length(),ans=1;
        int a=0,b=0,c=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(')a++;
            if(s[i]=='?')b++;
            if(s[i]==')')c++;
        }
        if((a-c+b)&1)ans=0;
        int x=(a-c+b)/2,y=b-x;
        if(y<0)ans=0;
        if(x<0)ans=0;
        for(int i=0;i<n;++i){
            if(s[i]=='?'){
                if(x)s[i]='(',x--;
                else s[i]=')',y--;
            }
        }
        for(int i=0,tot=0;i<n;++i){
            if(s[i]=='(')tot++;
            if(s[i]==')')tot--;
            if(tot<0)ans=0;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}