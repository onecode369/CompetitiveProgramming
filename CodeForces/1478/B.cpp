#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,q,d;
    cin >> t;
    while(t--){
        cin >> q >> d;
        bool flag;
        int x,y;
        for(int i=0;i<q;i++){
            cin >> y;
            x = y;
            flag  = false;
            int num1 = 0,ex = -1 ,cnt=1;
            while(x!=0){
                for(int j=1;j<=10;j++){
                    if(x%10 == ((d*j)%10)){
                        num1 = (j*cnt);
                        ex = j;
                        flag = true;
                        break;
                    }
                }
                if(flag)    break;
                x /= 10;
                cnt *= 10;
            }
            if(flag && (d*num1 <= y)){
                cout << "YES\n";
            }else        cout << "NO\n";
        }
    } 

    return 0;
}