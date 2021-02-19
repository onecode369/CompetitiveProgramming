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

    int t,A,B,n;
    cin >> t;
    while(t--){
        cin >> A >> B >> n;
        vector<pair<int,int>> mon(n);
        for(int i=0;i<n;i++)    cin >> mon[i].second;       
        for(int i=0;i<n;i++)    cin >> mon[i].first;
        sort(mon.begin(),mon.end());
        int j = 0;
        while(B > 0 && j < n){
            int y = min(ceil((B*1.0)/mon[j].second),ceil((mon[j].first*1.0)/A));
            B -= (y*mon[j].second);
            mon[j].first -= (y*A);
            if(mon[j].first > 0 && B > 0){
                B -= mon[j].second;
                mon[j].first -= A;
            }
            if(mon[j].first > 0)    j--;
            j++;
        }
        if(j == n)  cout << "YES\n";
        else        cout << "NO\n";
    }

    return 0;
}