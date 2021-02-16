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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t,a,b,k,x;
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        long long arr1[a],arr2[b];
        reset(arr1,a,0LL);
        reset(arr2,b,0LL);
        for(int i=0;i<k;i++){
            cin >> x;
            arr1[x-1]++; 
        }
        for(int i=0;i<k;i++){
            cin >> x;
            arr2[x-1]++; 
        }
        long long ans = (k*(k-1))/2;
        for(int i=0;i<a;i++)
            ans -= (arr1[i]*(arr1[i]-1))/2;
        for(int i=0;i<b;i++)
            ans -= (arr2[i]*(arr2[i]-1))/2;
        cout << ans << endl;
    }

    return 0;
}