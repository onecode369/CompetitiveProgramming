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

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int a[n],b[n],c[m];
        for(int i=0;i<n;i++)    cin >> a[i];
        for(int i=0;i<n;i++)    cin >> b[i];
        for(int i=0;i<m;i++)    cin >> c[i];
        bool flag = true;
        int ans[m];
        reset(ans,m,-1);
        for(int i=0;i<n;i++){
            if(b[i] != a[i] && b[i] == c[m-1]){
                flag = false;
                ans[m-1] = i+1;
                a[i] = b[i];
                break;
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                if(b[i] == c[m-1]){
                    ans[m-1] = i+1;
                    break;
                }
            }
        }
        vector<tuple<int,int,int>> colourChange;
        for(int i=0;i<n;i++){
            if(a[i] != b[i])    colourChange.emplace_back(make_tuple(i,a[i],b[i]));
        }
        for(int i=0;i<(m-1);i++)    ans[i] = ans[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<colourChange.size();j++){
                if(get<0>(colourChange[j]) != -1 && c[i] == get<2>(colourChange[j])){
                    a[get<0>(colourChange[j])] = b[get<0>(colourChange[j])];
                    ans[i] = get<0>(colourChange[j])+1;
                    get<0>(colourChange[j]) = -1;
                    break;
                }
            }
        }
        flag = true;
        for(int i=0;i<n;i++){
            if(a[i] != b[i])    flag = false;
        }
        if(flag && ans[m-1] != -1){
            cout << "YES\n";
            for(int i=0;i<m;i++)    cout << ans[i] << " ";
            cout << endl;
        }else   cout << "NO\n";
    }

    return 0;
}