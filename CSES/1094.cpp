#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long n;
    cin >> n;
    long long arr[n],ans = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i > 0 && arr[i] < arr[i-1]){
            ans += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << ans;

    return 0;
}