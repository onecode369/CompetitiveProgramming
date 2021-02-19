#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl

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
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    int cnt = 0;int ptl, ptr;
    for(int i=1; i<=n; i++){
        ptl = i; ptr = i;
        bool found = false;
        while(ptl>0 && ptr<=n && !found){
            if((arr[ptl]+arr[ptr]==2*arr[i]) && ptl!=ptr && (ptl!=i || ptr!=i)){
                cnt++; found = true;
            }
            else{
                if(arr[i]==arr[i-1]){
                    cnt++; found = true;
                }
                else if(arr[i]==arr[i+1]){
                    cnt++ ; found = true;
                }
            }
            if(arr[ptl]+arr[ptr]>2*arr[i]) ptl--;
            else ptr++;
        }
    }
    cout << cnt;

    return 0;
}