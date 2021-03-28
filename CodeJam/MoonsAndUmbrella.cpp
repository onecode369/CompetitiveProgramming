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

    int t,x,y;
    string s1,s;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> x >> y >> s1;
        int l = s1.length();
        s = "";
        int trm = 0;
        for(;trm<l;trm++){
            if(s1[trm] == '?'){
                while(trm < l && s1[trm] == '?'){
                    trm++;
                }
                trm--;
            }
            s.push_back(s1[trm]);
        }
        l = s.length();
        int dp[l+1];
        dp[0] = 0;
        dp[1] = 0;
        int a = 0,b=0;
        for(int j=2;j<=l;j++){
            if(s[j-1] == 'C'){
                if(s[j-2] == 'J'){
                    dp[j] = dp[j-1]+y;
                }else if(s[j-2] == '?'){
                    if(j > 2){
                        if(s[j-3] == 'J'){
                            dp[j] = dp[j-1]+y;
                        }else{
                            dp[j] = dp[j-2];
                        }
                    }else{
                        dp[j] = dp[j-2];
                    }
                }else{
                    dp[j] = dp[j-1];
                }
            }else if(s[j-1] == 'J'){
                if(s[j-2] == 'C'){
                    dp[j] = dp[j-1]+x;
                    a++;
                }else if(s[j-2] == '?'){
                    if(j > 2){
                        if(s[j-3] == 'C'){
                            dp[j] = dp[j-1]+x;
                        }else{
                            dp[j] = dp[j-2];
                        }
                    }else{
                        dp[j] = dp[j-2];
                    }
                }else{
                    dp[j] = dp[j-1];
                }        
            }else{
                dp[j] = dp[j-1];
            }
        }
        cout << "Case #" << i <<    ": " << dp[l] << endl;
    }

    return 0;
}