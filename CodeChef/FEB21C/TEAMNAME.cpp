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

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        map<string,vector<char>> mp;
        for(int i=0;i<n;i++){
            cin >> s;
            mp[s.substr(1,s.length()-1)].emplace_back(s[0]);
        }
        vector<vector<char>> vec;
        for(auto x : mp){
            vec.emplace_back(x.second);
            sort(vec[vec.size()-1].begin(),vec[vec.size()-1].end());
        }
        int ans = 0;
        for(int i=0;i<vec.size()-1;i++){
            for(int j=i+1;j<vec.size();j++){
                vector<char> vInt;
                set_intersection(
                    vec[i].begin(), vec[i].end(),
                    vec[j].begin(), vec[j].end(),
                    back_inserter(vInt)
                );
                ans += ((vec[i].size()-vInt.size())*(vec[j].size()-vInt.size()));
            }
        }
        cout << 2*ans << endl;
    }

    return 0;
}