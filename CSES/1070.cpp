#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    if(n <= 3 && n != 1)  cout << "NO SOLUTION";
    else if(n == 1) cout << "1";
    else if(n == 4) cout << "3 1 4 2";
    else{
        int x;
        if(n%2 == 0)    x = n/2;
        else            x = (n+1)/2;
        for(int i=1;i<=x;i++){
            if(i == x){
                cout << i << " ";
                if(n%2 == 0)    cout << n;
            }else{
                cout << i << " " << x+i << " ";
            }
        }
    }

    return 0;
}