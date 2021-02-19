#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr,arr+n,i)

using namespace std;

bool isRepFreeNum(int x){
    int arr[10];
    reset(arr,10,0);
    while(x != 0){
        arr[x%10]++;
        if((x%10 == 0) || (arr[x%10] > 1))
            return false;
        x /= 10;
    }
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    if(n >= 987654321){
        cout << "0\n";
    }else{
        for(int i=n+1;i<=987654321;i++)
            if(isRepFreeNum(i)){
                cout << i << " ";
                break;
            }
    }

    return 0;
}