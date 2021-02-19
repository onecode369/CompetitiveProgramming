#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    const int x = n;
    vector<char> bin(n,'0');
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++)    cout << bin[j];
        cout << endl;
        while (next_permutation(bin.begin(),bin.end())){
            for(int j=0;j<n;j++)    cout << bin[j];
            cout << endl;
        }
        if(i != n) bin[i] = '1';
    }

    return 0;
}