#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n,n1,q;
    cin >> n >> q;
    n1 = n;
    long long arr[n+1];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(n%2 != 0){
        arr[n] = arr[n-1];
        n++;
    }
    vector<long long> gcds(2*n,0);
    for(int i=n;i<2*n;i++){
        gcds[i] = arr[i-n];
    }
    for(int i=n-1;i>0;i--){
        gcds[i] = __gcd(gcds[2*i],gcds[2*i+1]);
    }
    long long pos,x,rpos=n-1;
    for(int i=0;i<2*n;i++){
        if(gcds[i] != 0){
            rpos = i;
            break;
        }
    }
    while(q--){
        cin >> pos >> x;
        if(pos == n1 && n1%2!=0){
            gcds[pos+n] *= x;
            gcds[pos+n] %= MOD;
        }
        gcds[n+pos-1] *= x;
        gcds[n+pos-1] %= MOD;
        pos += n;
        pos--;
        if(pos%2!=0) pos--;
        pos /= 2;
        while(pos != 0){
            gcds[pos] = __gcd(gcds[2*pos],gcds[2*pos+1]);
            if(pos%2 != 0) pos--;
            pos /= 2;
        }
        cout << gcds[rpos] << endl;
    }

    return 0;
}