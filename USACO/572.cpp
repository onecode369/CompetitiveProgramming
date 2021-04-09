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
    int n,q;
    cin >> n >> q;
    int arr[n],arr1[n],arr2[n],arr3[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    arr1[0] = arr2[0] = arr3[0] = 0;
    for(int i=1;i<=n;i++){
    	arr1[i] = arr1[i-1];
    	arr2[i] = arr2[i-1];
    	arr3[i] = arr3[i-1];
    	if(arr[i-1] == 1)			arr1[i]++;
    	else if(arr[i-1] == 2)	arr2[i]++;
    	else					arr3[i]++;
    }
    int x,y;
    while(q--){
    	cin >> x >> y;
    	cout << (arr1[y]-arr1[x-1]) << " " << (arr2[y]-arr2[x-1]) << " " << (arr3[y]-arr3[x-1]) << endl;
    }
}

signed main(){
    freopen("bcount.in","r", stdin );
    freopen("bcount.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}