#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define ll long long

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        set<ll> s;
        ll x;
        bool flag = true;
        for(int i=0;i<2*n;i++){
            cin >> x;
            if(x%2 != 0) flag = false;
            s.insert(x);
        }
        if(s.size() != n) flag = false;
        if(flag){
            ll sum = 0;
            stack<ll> st;
            for(int x : s){
                st.push(x);
            }
            flag = true;
            while(!st.empty()){
                if((st.top()-(2*sum))%(2*st.size()) != 0){
                    flag = false;
                    break;
                }
                sum += (st.top()-(2*sum))/(2*st.size());
                st.pop();
            }
            if(flag)    cout << "YES\n";
            else        cout << "NO\n";
        }else{
            cout << "NO\n";
        }
    }    

    return 0;
}