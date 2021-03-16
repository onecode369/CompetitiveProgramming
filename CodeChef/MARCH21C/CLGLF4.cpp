#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF 1000000000000000000LL
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t,n,e,h,a,b,c,x;
    cin >> t;
    while(t--){
        cin >> n >> e >> h >> a >> b >> c;
        long long ans=INF,num=0,tempAns=0;
        if(min(e,h) >= n){
            num = n;
        }else{
            num = min(e,h);
        }
        tempAns += c*num;
        if(num < n){
            if(a < b){
                if(((e-min(e,h))/2) >= (n-num)){
                    tempAns += (n-num)*a;
                    num = n;
                }else{
                    tempAns += ((e-min(e,h))/2)*a;
                    num += ((e-min(e,h))/2);
                }
                if(num < n){
                    tempAns += (n-num)*b;
                    num += ((h-min(e,h))/3);
                }
            }else{
                if(((h-min(e,h))/3) >= (n-num)){
                    tempAns += (n-num)*b;
                    num = n;
                }else{
                    tempAns += ((h-min(e,h))/3)*b;
                    num += ((h-min(e,h))/3);
                }
                if(num < n){
                    tempAns += (n-num)*a;
                    num += ((e-min(e,h))/2);
                }
            }
        }
        if(num >= n)    ans = min(ans,tempAns);
        num = 0;tempAns = 0;
        if((e/2) >= n){
            num = n;
        }else{
            num = (e/2);
        }
        tempAns = a*num;
        if(num < n){
            if(e%2 == 0){
                if((h/3) >= (n-num)){
                    tempAns += (n-num)*b;
                    num = n;
                }else{
                    tempAns += (h/3)*b;
                    num += (h/3);
                }
            }else{
                long long x=INF,y=INF;
                if(((h-1)/3) >= (n-num-1))
                    x = c+((n-num-1)*b);
                if((h/3) >= (n-num))
                    y = ((n-num)*b);
                if(y != INF) x = min(x,y);
                if(x != INF) num = n;
                tempAns += x;
            }
        }
        if(num >= n) ans = min(ans,tempAns);
        num = 0;tempAns = 0;
        if((h/3) >= n){
            num = n;
        }else{
            num = (h/3);
        }
        tempAns = b*num;
        if(num < n){
            if(h%3 == 0){
                if((a/2) >= (n-num)){
                    tempAns += (n-num)*a;
                }
            }else{
                long long x = INF,y = INF;
                if((h%3 == 1) || (e == 1)){
                    if(e){
                        x += c;
                        if(((e-1)/2) >= (n-num-1)){
                            x += (n-num-1)*a;
                        }else{
                            x = INF;
                        }
                        if((e/2) >= (n-num)){
                            y = (n-num)*a;
                        }
                        x = min(x,y);
                        if(x != INF){
                            num = n;
                            tempAns += x;
                        }
                    }    
                }else{
                    if(e){
                        x = 2*c;
                        if(((e-2)/2) >= (n-num-2)){
                            x += (n-num-1)*a;
                        }else{
                            x = INF;
                        }
                        if((e/2) >= (n-num)){
                            y = (n-num)*a;
                        }
                        x = min(x,y);
                        if(x != INF){
                            num = n;
                            tempAns += x;
                        }
                    }
                }
            }
        }
        if(num >= n)    ans = min(ans,tempAns);
        if(ans == INF)    cout << "-1\n";
        else            cout << ans << endl;
    }

    return 0;
}
