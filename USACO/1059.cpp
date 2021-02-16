#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int arr[7];
    for(int i=0;i<7;i++)
        cin >> arr[i];
    sort(arr,arr+7);
 
    cout << arr[0] << " " << arr[1] << " " << arr[6] - (arr[0] + arr[1]);

    return 0;
}