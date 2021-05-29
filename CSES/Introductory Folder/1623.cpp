#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int n;

int div(int* arr, int i, int s1, int s2){
	if(i == n)
		return abs(s1-s2);
	return min(div(arr, i+1, s1+arr[i], s2),
				div(arr, i+1, s1, s2+arr[i]));
}

void solve(){
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    cout << div(arr, 0, 0, 0);
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