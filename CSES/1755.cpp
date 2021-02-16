#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    int arr[26];
    reset(arr,26,0);
    for(int i=0;i<s.length();i++)
        arr[s[i]-'A']++;
    int cnt = 0,idx = -1;
    for(int i=0;i<26;i++)
        if(arr[i]%2 != 0){
            cnt++;
            idx = i;
        }

    if(cnt > 1) cout << "NO SOLUTION\n";
    else{
        for(int i=0;i<26;i++)
            for(int j=0;j<(arr[i]/2);j++)
                cout << char((int) 'A' + i);
        if(idx != -1)   cout << char((int) 'A' + idx);
        for(int i=25;i>=0;i--)
            for(int j=0;j<(arr[i]/2);j++)
                cout << char((int) 'A' + i);
    }
    return 0;
}