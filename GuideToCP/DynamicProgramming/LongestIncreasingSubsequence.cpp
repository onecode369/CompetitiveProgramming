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

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int tmp[n],trk[n];
    vector<int> tmpValue;
    reset(trk,n,-1);
    tmp[0] = 0;
    tmpValue.emplace_back(arr[0]);
    vector<int>::iterator lwrbnd;
    int idx;
    for(int i=1;i<n;i++){
        lwrbnd = lower_bound(tmpValue.begin(),tmpValue.end(),arr[i]);
        idx = lwrbnd - tmpValue.begin();
        if(idx > 0)
        trk[idx] = tmp[idx-1];
        if((unsigned int)idx < (unsigned int)tmpValue.size())
            tmpValue[idx] = arr[i];
        else
            tmpValue.emplace_back(arr[i]);
        tmp[idx] = i;
    }
    cout << tmpValue.size();

    return 0;
}
