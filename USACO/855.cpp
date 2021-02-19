#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c1,c2,c3;
    int i1,i2,i3;
    cin >> c1 >> i1;
    cin >> c2 >> i2;
    cin >> c3 >> i3;
    
    int l = 0;

    for(int i=0;i<100;i++){
        if(i%3 == 0){
            l = c2-i2;
            if(l >= i1){
                i2 += i1;
                i1 = 0;
            }else{
                i2 = c2;
                i1 = i1-l;
            }
        }else if(i%3 == 1){
            l = c3-i3;
            if(l >= i2){
                i3 += i2;
                i2 = 0;
            }else{
                i3 = c3;
                i2 = i2-l;
            }
        }else{
            l = c1-i1;
            if(l >= i3){
                i1 += i3;
                i3 = 0;
            }else{
                i1 = c1;
                i3 = i3-l;
            }
        }
    }
    cout << i1 << endl;
    cout << i2 << endl;
    cout << i3 << endl;

    return 0;
}