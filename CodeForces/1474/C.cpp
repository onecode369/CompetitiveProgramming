#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

void fillOut(int* arr,queue<pair<int,int>>& q,map<int,int>& mp,map<int,int>& mp1,int n){
    if(q.size() == n)  return;
    if(q.empty()) return;
    int x = q.front().first;
    for(int i=2*n-2;i>=0;i--){
        x = q.front().first;
        if(mp[x-arr[i]] == 1 && mp1[x-arr[i]] == 1 && mp1[arr[i]] == 1){
            q.push({arr[i],x-arr[i]});
            mp1[arr[i]] = -1;
            mp1[x-arr[i]] = -1;
            fillOut(arr,q,mp,mp1,n);
        }
    }
    if(x == q.front().first){
        mp1[x] = 1;
        mp1[q.front().second] = 1;
        q.pop();
    }
}

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
        int arr[2*n];
        map<int,int> mp,mp1;
        for(int i=0;i<2*n;i++){
            cin >> arr[i];
            mp[arr[i]] = 1;
            mp1[arr[i]] = 1;
        }
        if(n%2 != 0) cout << "NO\n";
        else{
            queue<pair<int,int>> q;
            sort(arr,arr+(2*n));
            mp1[arr[2*n-1]] = -1;
            q.push({arr[2*n-1],-1});
            fillOut(arr,q,mp,mp1,n);
            if(q.size() == n){
                cout << "YES\n";
                cout << arr[2*n-1] << " ";
                for(auto x : mp1){
                    if(x.second != -1)
                        cout << x.first << endl;
                }
                q.pop();
                for(int i=1;i<n;i++){
                    cout << q.front().first << " " << q.front().second << endl;
                    q.pop();
                }
            }else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}