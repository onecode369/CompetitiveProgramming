#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool solve(string a,int len,char A,char B,char C){
    stack<char> st;
    int i = 0;
    char X;
    while(i != len){
        if(a[i] == 'A')       X = A;
        else if(a[i] == 'B')  X = B;
        else                  X = C;
        if(X == '('){
            st.push('(');
        }else{
            if(st.size() > 0){
                st.pop();
            }else   return false;
        }
        i++;
    }
    if(st.size() > 0)   return false;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    string a;
    while(t--){
        cin >> a;
        int len = a.length();
        char A='A',B='B',C='C';
        if(a[0] == a[len-1]){
            cout << "NO\n";
        }else{
            if(a[0] == 'A')         A = '(';
            else if(a[0] == 'B')    B = '(';
            else                    C = '(';
            if(a[len-1] == 'A')         A = ')';
            else if(a[len-1] == 'B')    B = ')';
            else                        C = ')';
            bool ans = false;
            for(int i=0;i<2;i++){
                if(A == 'A'){
                    if(i == 0)  ans = solve(a,len,'(',B,C);
                    else        ans = solve(a,len,')',B,C);
                }else if(B == 'B'){
                    if(i == 0)  ans = solve(a,len,A,'(',C);
                    else        ans = solve(a,len,A,')',C);
                }else{
                    if(i == 0)  ans = solve(a,len,A,B,'(');
                    else        ans = solve(a,len,A,B,')');
                }
                if(ans) break;
            }
            if(ans) cout << "YES\n";
            else    cout << "NO\n";
        }   
    }

    return 0;
}