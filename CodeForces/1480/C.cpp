#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    int x = ceil((n-2)/32);
    int c[7];
    cout << "? 1" << endl;
    cin >> c[0];
    cout << "? 2" << endl;
    cin >> c[1];
    bool flag = false;
    if(c[0] < c[1]) cout << "! 1" << endl;
    else{
        for(int i = 1;i<=x;i++){
            cout << "? " << 1+(i*32) << endl;
            cin >> c[2];
            cout << "? " << 2+(i*32) << endl;
            cin >> c[3];
            cout << "? " << 3+(i*32) << endl;
            cin >> c[4];
            if(c[3] < c[2] && c[3] < c[4]){
                cout << "! " << 2+(i*32) << endl;
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        cout << "? " << n-1 << endl;
        cin >> c[5];
        cout << "? " << n << endl;
        cin >> c[6];
        if(c[6] < c[5]) cout << "! " << n << endl;
    }

    return 0;
}