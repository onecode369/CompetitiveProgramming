#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int timeInInt(string s){
    if(s.substr(0,2) == "12"){
        s[0] = '0';
        s[1] = '0';
    }
    int t = (stoi(s.substr(0,2))*60)+(stoi(s.substr(3,2)));
    if(s.substr(5,2) == "PM")   t += 720;
    return t;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t,n,fst;
    string timeAlloted[2];
    cin >> t;
    while(t--){
        cin >> timeAlloted[0] >> timeAlloted[1];
        fst = timeInInt(timeAlloted[0]+timeAlloted[1]);
        cin >> n;
        string friendsTimeStart[2],friendsTimeEnd[2];
        int st,en;
        for(int i=0;i<n;i++){
            cin >> friendsTimeStart[0] >> friendsTimeStart[1];
            cin >> friendsTimeEnd[0] >> friendsTimeEnd[1];
            st = timeInInt(friendsTimeStart[0]+friendsTimeStart[1]);
            en = timeInInt(friendsTimeEnd[0]+friendsTimeEnd[1]);
            if(st <= fst && en >= fst)  cout << "1";
            else                        cout << "0";
        }
        cout << endl;
    }

    return 0;
}