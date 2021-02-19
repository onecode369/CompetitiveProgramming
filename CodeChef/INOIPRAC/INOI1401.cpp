#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX

using namespace std;

void ans(int** arr,int r,int c,int x,int y){
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int r,c,d;
    cin >> r >> c >> d;
    int arr[r][c],ans[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> arr[i][j];

    ans(arr,r,c,r-1,c-1);

    return 0;
}