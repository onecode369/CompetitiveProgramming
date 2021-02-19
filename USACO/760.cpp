#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int arr1[n+1],arr2[n+1],arr3[n+1];    
    for(int i=1;i<=n;i++)
        cin >> arr1[i];
    for(int i=1;i<=n;i++)
        cin >> arr2[i];
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++) arr3[j] = arr2[arr1[j]];
        for(int j=1;j<=n;j++) arr2[j] = arr3[j];
    }
    for(int i=1;i<=n;i++)
        cout << arr2[i] << endl;

    return 0;
}