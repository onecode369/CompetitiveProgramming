#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

char icecream[1005][1005];

pair<int,int> icecream_details(int n, int i, int j){
    if(i == n || j == n)
        return make_pair(0, 0);
    icecream[i][j] = '*';
    pair<int,int> ans,ans1,ans2,ans3,ans4;
    ans1 = ans2 = ans3 = ans4 = make_pair(0, 0);
    ans.first = 0;ans.second = 1;
    if(i!=0 && icecream[i-1][j] == '#')
        ans1 = icecream_details(n, i-1, j);
    if(j!=0 && icecream[i][j-1] == '#')
        ans4 = icecream_details(n, i, j-1);
    if(n != 1){
        if(icecream[i+1][j] == '#')
            ans3 = icecream_details(n, i+1, j);
        if(icecream[i][j+1] == '#')
            ans2 = icecream_details(n, i, j+1);
    }
    if(i == 0 || icecream[i-1][j] == '.')   ans.first++;
    if(i == n-1 || icecream[i+1][j] == '.')   ans.first++;
    if(j == 0 || icecream[i][j-1] == '.')   ans.first++;
    if(j == n-1 || icecream[i][j+1] == '.')   ans.first++;
    return make_pair(
        ans.first + ans1.first + ans2.first + ans3.first + ans4.first,
        ans.second + ans1.second + ans2.second + ans3.second + ans4.second
    );
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> icecream[i][j];
    pair<int,int> ans;
    int perimeter=-1, area = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(icecream[i][j] == '#'){
                ans = icecream_details(n, i, j);
                if(ans.second >= area){
                    area = ans.second;
                    perimeter = max(perimeter,ans.first);
                }
            }
        }
    }
    if(area == -1)  area = perimeter = 0;
    cout << area << " " << perimeter;
}

signed main(){
    freopen("perimeter.in","r", stdin );
    freopen("perimeter.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}