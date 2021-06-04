#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) < 1e-9) ? 1 : 0)

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

//////////////////////////////////DEBUG////////////////////////////////////////

#ifdef ONECODE369
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
    
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t << "\n";}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{\n"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[\n"; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(queue <T> v) {cerr << "[\n"; queue <T> dv = v; while(!dv.empty()) {_print(dv.front()); dv.pop(); cerr << " ";} cerr << "]\n";}
template <class T> void _print(stack <T> v) {cerr << "[\n"; stack <T> dv = v; while(!dv.empty()) {_print(dv.top()  ); dv.pop(); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[\n"; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}

namespace{
    int N;
    const int QMAX = 120;
    int a, b, asked;
}

bool doesPathExist(const vector<string> & M){
    debug(M)
    if(asked == QMAX){
        cerr << "Asked too many queries" << endl;
        exit(0);
    }
    if((int)M.size() != N){
        cerr << "Invalid query" << endl;
        exit(0);
    }
    for(int i = 0; i < N; i++){
        if((int)M[i].length() != N){
            cerr << "Invalid query" << endl;
            exit(0);
        }
        for(int j = 0; j < N; j++){
            if(M[i][j] != '0' && M[i][j] != '1'){
                cerr << "Non 0-1 character in M" << endl;
                cout << 0 << endl;
                exit(0);
            }
        }
    }
    asked++;
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    dp[0][0] = M[0][0] == '1';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(i + j && (M[i][j] == '1' || (i == a && j == b))){
            if(i && dp[i - 1][j]) dp[i][j] = true;
            if(j && dp[i][j - 1]) dp[i][j] = true;
        }
    }
    return dp[N - 1][N - 1];
}

pair<int, int> findHiddenCell(int N){
    vector<string> M(N);
    M = {

        "11000000000000000000000000000000000000000000000000",
        "11111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111110",
        "01111111111111111111111111111111111111111111111111",
        "00000000000000000000000000000000000000000000000011"

    };
    int x = -1, y = -1;
    for(int i=1;i<49;i++){
        for(int j=1;j<49;j++)
            M[i][j] = '0';
        if(doesPathExist(M)){
            cerr << "YES\n";
            x = i;
            for(int j=1;j<49;j++)
                M[i][j] = '1';
            break;
        }
        for(int j=1;j<49;j++)
            M[i][j] = '1';
        cerr << "NO\n";
    }
    for(int i=1;i<49;i++){
        for(int j=1;j<49;j++)
            M[j][i] = '0';
        if(doesPathExist(M)){
            cerr << "YES\n";
            y = i;
            break;
        }
        for(int j=1;j<49;j++)
            M[j][i] = '1';
        cerr << "NO\n";
    }
    return make_pair(x, y);
}

int main(){
    freopen("cell.in","r", stdin );
    freopen("cell.out","w",stdout);
    freopen("cell.err","w",stderr);
    int T; cin >> T;
    while(T--){
        cin >> N;
        asked = 0;
        cin >> a >> b;
        pair<int, int> P = findHiddenCell(N);
        
        if(P != make_pair(a, b)){
            cerr << "Incorrect output!" << endl;
            cerr << "Expected: " << "(" <<a<<", " << b << ")" << endl;
            cerr << "Got: " << "(" <<P.first<<", " << P.second << ")" << endl;
            exit(0);
        }
        cerr << "Correct output!" << endl;
        cerr << "Queries asked = " << asked << endl;
    }
}