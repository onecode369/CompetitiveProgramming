#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

long long overlap(long long a1, long long b1, long long a2, long long b2){
    return max(min(a2, b2) - max(a1, b1), (long long)0);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    long long ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
 
    long long bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;
 
    long long cx1, cy1, cx2, cy2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;
 
    long long a = (ay2 - ay1) * (ax2 - ax1);
    long long aby = overlap(ay1, by1, ay2, by2);
    long long abx = overlap(ax1, bx1, ax2, bx2);
    long long ab = aby * abx;
 
    long long acy = overlap(ay1, cy1, ay2, cy2);
    long long acx = overlap(ax1, cx1, ax2, cx2);
    long long ac = acy * acx;
 
    long long abcy = max(min({ay2, by2, cy2}) - max({ay1, by1, cy1}), (long long)0);
    long long abcx = max(min({ax2, bx2, cx2}) - max({ax1, bx1, cx1}), (long long)0);
    long long abc = abcx * abcy;
 
    if (ab + ac - abc >= a){
        cout << "NO";
    }else{
        cout << "YES";
    }

    return 0;
}