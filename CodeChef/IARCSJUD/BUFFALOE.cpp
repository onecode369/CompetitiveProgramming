#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr,arr+n,i)
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,k;
    cin >> n >> k;
    int market[n];
    for(int i=0;i<n;i++){
        cin >> market[i];
    }
    k = (k/2)*2;
    
    vector<vector<int> > stockTable(k+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            stockTable[j][i] = 0;
        }
    }
    for(int i=1;i<=k;i++){
        vector<int> stocks = stockTable[i-1];
        for(int j=i;j<=n;j++){
            if(i%2 !=0){
                stockTable[i][j] = *max_element(stocks.begin()+i-1,stocks.begin()+j) - market[j-1];
            }else{
                stockTable[i][j] = *max_element(stocks.begin()+i-1,stocks.begin()+j) + market[j-1];
            }
        }
    }
    vector<int> lastTrans = stockTable[k];
    cout << *max_element(lastTrans.begin(),lastTrans.end()) << endl;

    return 0;
}