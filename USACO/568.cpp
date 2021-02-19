#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin >> n >> m;
    int arr1[n][2],arr2[m][2];
    for(int i=0;i<n;i++){
        cin >> arr1[i][0] >> arr1[i][1];
        if(i != 0)
            arr1[i][0] += arr1[i-1][0];
    }
    for(int i=0;i<m;i++){
        cin >> arr2[i][0] >> arr2[i][1];
        if(i != 0)
            arr2[i][0] += arr2[i-1][0];
    }

    int idx = 0,ans = 0;
    for(int i=0;i<m;i++){
        if(arr1[idx][0] < arr2[i][0]){
            if(i != 0){
                if(arr1[idx][0] > arr2[i-1][0]){
                    ans = max(ans,arr2[i][1]-arr1[idx][1]);
                }
            }else{
                ans = max(ans,arr2[i][1]-arr1[idx][1]);
            }
            while(arr1[idx][0] < arr2[i][0]){
                if(i > 0 && arr1[idx][0] > arr2[i-1][0]){
                    ans = max(ans,arr2[i][1]-arr1[idx][1]);
                }
                idx++;
            }
        }
        ans = max(ans,arr2[i][1]-arr1[idx][1]); 
    }
    cout << ans;

    return 0;
}