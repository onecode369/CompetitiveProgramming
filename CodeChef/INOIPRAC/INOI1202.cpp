#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    multiset<int> sm;
    multiset<int>::iterator it;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sm.insert(arr[i]+i+1);
    }

    for(int i=0;i<n;i++){
        it = sm.end();
        cout << *(--it)+i << " ";
        it = sm.find(arr[n-i-1]+n-i);
        sm.erase(it);
        sm.insert(arr[n-i-1]-i);
    }

    return 0;
}
