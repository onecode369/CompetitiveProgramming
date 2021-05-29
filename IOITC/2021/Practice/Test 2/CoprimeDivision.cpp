#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int prime[2000005];

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr1(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin >> arr1[i].first;
    	arr1[i].second = i+1;
    }
    sort(arr1.begin(), arr1.end());
    for(int i=0;i<n;i++)
    	arr[i] = arr1[i].first;
    map<int,int> div1, div2, div3;
    vector<int> v1,v2,v3;
    int x = arr[0];
    v1.emplace_back(arr1[0].second);
    while(x >= 1){
    	div1[prime[x]] = 1;
    	int y = prime[x];
    	while(y != 1 && x % y == 0)
    		x /= y;
    	if(x == 1)	break;
    }
    for(int i=1;i<n;i++){
    	x = arr[i];
    	bool flag1 = true,flag2 = true,flag3 = true;
    	vector<int> div;
    	while(x >= 1){
    		div.emplace_back(prime[x]);
    		if(div1.count(prime[x]) != 0)	flag1 = false;
    		if(div2.count(prime[x]) != 0)	flag2 = false;
    		if(div3.count(prime[x]) != 0)	flag3 = false;
    		int y = prime[x];
    		while(y != 1 && x % y == 0)
    			x /= y;
    		if(x == 1)	break;
    	}
    	if(!flag1 && !flag2)	break;
    	if(!flag1 && !flag3)	break;
    	if(!flag2 && !flag3)	break;
    	bool flag = false;
    	for(int j=0;j<(int) div.size();j++){
    		if(!flag1)					div2[div[j]] = 1;
    		else if(!flag2 || !flag3)	div1[div[j]] = 1;
    		else						div3[div[j]] = 1;	
    	}
    	if(!flag1)					v2.emplace_back(arr1[i].second);
    	else if(!flag2 || !flag3)	v1.emplace_back(arr1[i].second);
    	else						v3.emplace_back(arr1[i].second);
    }
    if((int) v2.size() > (int) v1.size())
    	swap(v1, v2);
    for(int i=0;i<(int) v3.size();i++){
    	v1.emplace_back(v3[i]);
    }
    if((int) v1.size() + (int) v2.size() < n)	cout << "-1\n";
    else{
    	cout << (int) v1.size() << endl;
    	sort(v1.begin(), v1.end());
    	for(int i=0;i<(int) v1.size();i++)
    		cout << v1[i] << " ";
    	cout << endl;
    }
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=1;i<=2000000;i++)	prime[i] = i;
    for(int i=2;i<=1500;i++)
    	if(prime[i] == i)
    		for(int j=i+i;j<=2000000;j+=i)
    			if(prime[j] == j)	prime[j] = i;

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}