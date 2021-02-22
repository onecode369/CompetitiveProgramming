#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0) 

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double x = 0.3*3+0.1;
    double y = 1;
    cout << setprecision(20) << x << endl;
    if(x == y)  cout << "OK" << endl;
    else        cout << "Failed" << endl; 

    if(iseql(x,y))  cout << "OK" << endl;
    else        cout << "Failed" << endl; 

    return 0;
}