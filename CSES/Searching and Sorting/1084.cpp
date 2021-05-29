#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int arr1[n],arr2[m];
    for(int& x : arr1)
    	cin >> x;
    for(int& x : arr2)
    	cin >> x;
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int cnt = 0,i=n-1,j=m-1;
    while(j >= 0 && i >= 0){
    	if(arr1[i] > arr2[j]+k)
    		i--;
    	else if(arr1[i] < arr2[j]-k)
    		j--;
    	else{
    		i--;
    		j--;
    		cnt++;
    	}
    }
    cout << cnt;
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}