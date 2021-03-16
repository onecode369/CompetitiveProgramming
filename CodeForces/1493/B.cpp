#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

bool isMirror(int t){
    int x = t%10,y = t/10;
    if(!(x == 0 || x == 1 || x == 2 || x == 5 || x == 8))   return false;
    if(!(y == 0 || y == 1 || y == 2 || y == 5 || y == 8))   return false;
    return true;
}

int mirror(int num){
    int x = num%10,y = num/10;
    if(x == 2)      x = 5;
    else if(x == 5) x = 2;
    if(y == 2)      y = 5;
    else if(y == 5) y = 2;
    return 10*x+y;    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,h,m;
    string s;
    cin >> t;
    while(t--){
        cin >> h >> m >> s;
        int maxTime = h*m;
        int hr = stoi(s.substr(0,2));
        int min = stoi(s.substr(3,2));
        int lMin1 = min,lMin2 = min;
        int lHr1 = hr,lHr2 = hr;
        while(lMin1 != m){
            if(isMirror(lMin1) && (mirror(lMin1) < h))  break;
            lMin1++;
        }
        while(lMin2 != 0){
            lMin2--;
            if(isMirror(lMin2) && (mirror(lMin2) < h))  break;
        }
        if(lMin1 == m || abs(lMin1-h) >= abs(lMin2-h)){
            lMin1 = lMin2;
        }
        while(lHr1 != h){
            if(isMirror(lHr1) && (mirror(lHr1) < m))  break;
            lHr1++;
        }
        while(lHr2 != 0){
            lHr2--;
            if(isMirror(lHr2) && (mirror(lHr2) < m))  break;
        }
        if(lHr1 == m || abs(lHr1-h) >= abs(lHr2-h)){
            lHr1 = lHr2;
        }
        if(lHr1*m + lMin2 >= maxTime){
            cout << "00:00\n";
        }else{
            if(lHr1 < 10)   cout << "0";
            cout << lHr1 << ":";
            if(lMin1 < 10)  cout << "0";
            cout << lMin1 << "\n";
        }
    }

    return 0;
}