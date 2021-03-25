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

    int t,n,k;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        vector<int> dot;
        for(int i=0;i<n;i++)
            if(s[i] == '*')
                dot.emplace_back(i);
        int cnt = 0,pdot = -1;
        bool flag = true;
        if(dot.size() > 0){
            pdot = dot[0];
            cnt++;
            if(dot.size() > 1)
                cnt++;
        }
        for(int i=1;i<(dot.size()-1);i++){
            if(dot[i]-pdot-1 >= k){
                if(pdot == dot[i-1]){
                    flag = false;
                    break;
                }else{
                    pdot = dot[i-1];
                    cnt++;
                }
            }
        }
        if(dot.size() > 1){
            if(dot[dot.size()-1]-pdot-1 >= k){
                cnt++;
            }
        }
        if(flag)    cout << cnt << endl;
        else                 cout << "-1\n";
    }

    return 0;
}