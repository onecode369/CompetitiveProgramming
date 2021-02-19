#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    int ans1 = 0,ans2 = 0,ans3 = 0,a,b,g;
    int arr[4] = {0,1,2,3};
    cin >> n;
    while(n--){
        cin >> a >> b >> g;
        swap(arr[a],arr[b]);
        if(arr[g] == 1)         ans1++;
        else if(arr[g] == 2)    ans2++;
        else if(arr[g] == 3)    ans3++;
    }
    cout << max(ans1,max(ans2,ans3));

    return 0;
}