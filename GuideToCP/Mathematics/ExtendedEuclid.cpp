#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

tuple<int,int,int> gcd(int a,int b){
    if(b == 0){
        return {1,0,a};
    }
    int x,y,g;
    tie(x,y,g) = gcd(b,a%b);
    return {y,x-(a/b)*y,g};
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a,b;
    cin >> a >> b;
    int x,y,g;
    tie(x,y,g) = gcd(a,b);
    cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << g; 

    return 0;
}