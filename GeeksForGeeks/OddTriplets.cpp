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

    int n,x;
    cin >> n >> x;
    int arr[n];
    vector<pair<int,int>> odd;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]%2 != 0)
            odd.emplace_back(make_pair(arr[i],i));
    }
    int pos1,pos2=0,pos3 = -1;
    for(int i=1;i<odd.size();i++){
        if(odd[i].second-odd[0].second >= x){
            pos3 = i;
            break;
        }
    }
    if(pos3 == -1){
        cout << 0;
    }else{
        int cnt=0,x=-1;
        while(true){
            pos1 = pos2;
            pos2 = pos3;
            x = -1;
            for(int i=pos2+1;i<odd.size();i++){
                if(odd[i].second-odd[pos2].second >= x){
                    x = i;
                    break; 
                }
            }
            if(x == -1) break;
            else{
                pos3 = x;
                cnt += (n-odd[x].second);
            }
        }
        cout << cnt;
    }

    return 0;
}