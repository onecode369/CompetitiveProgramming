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

    int t,x,y;
    string s;
    cin >> t;
    while(t--){
        cin >> x >> y >> s;
        int px=0,nx=0,py=0,ny=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'U')         py++;
            else if(s[i] == 'D')    ny++;
            else if(s[i] == 'R')    px++;
            else if(s[i] == 'L')    nx++;
        }
        bool flag = true;
        if((x < 0) && ((-1*x) > nx)) flag = false;
        else if((x > 0) && (x > px)) flag = false;
        if((y < 0) && ((-1*y) > ny)) flag = false;
        else if((y > 0) && (y > py)) flag = false;
        if(flag)    cout << "YES\n";
        else        cout << "NO\n";
    }

    return 0;
}