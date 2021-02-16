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

    int arr[1000001];
    for(int i=0;i<=1000000;i++)
        arr[i] = 1;
    arr[0] = arr[1] = 0;
    for(int i=2;i<=sqrt(1000000);i++)
        if(arr[i] == 1)
            for(int j=i*i;j<=1000000;j+=i)
                arr[j] = 0;

    int numprime[1000001] = {0};
    for(int i=2;i<1000001;i++){
        if(arr[i] == 1)
            numprime[i] = numprime[i-1] + 1;
        else
            numprime[i] = numprime[i-1];
    }

    int arr1[1000001] = {0};
    for(int i=3;i<1000001;i++){
        if(arr[numprime[i]] == 1)
            arr1[i] = 1;
    }

    int numprime1[1000001] = {0};
    for(int i=2;i<1000001;i++){
        if(arr1[i] == 1)
            numprime1[i] = numprime1[i-1] + 1;
        else
            numprime1[i] = numprime1[i-1];
    }

    int t,l,r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << numprime1[r] << " " <<  numprime1[l] << endl;

    }

    return 0;
}