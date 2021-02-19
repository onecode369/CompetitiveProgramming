#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int l,r;
    cin >> l >> r;
    int arr[10002];
    for(int i=0;i<=10001;i++)
        arr[i] = 1;
    arr[0] = arr[1] = 0;
    for(int i=2;i<=sqrt(10001);i++)
        if(arr[i] == 1)
            for(int j=i*i;j<=10001;j+=i)
                arr[j] = 0;

    for(int i=l;i<=r;i++)
        if(arr[i] == 1)
            cout << i << " "; 

    return 0;
}