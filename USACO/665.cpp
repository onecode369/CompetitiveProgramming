#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,k;
    char ch;
    string s;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        s = "";
        for(int j=0;j<m;j++){
            cin >> ch;
            for(int l=0;l<k;l++)
                s = s + ch; 
        }
        for(int l=0;l<k;l++)
            cout << s << endl;
    }

    return 0;
}