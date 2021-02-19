#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 998244353
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

long long powerOfTwo[300001];
bool flag = false;

pair<int,int> bfs(vector<int>* adjList,int* visited,bool* even,int n,int node){
    queue<int> q;
    int e=1,o=0;
    visited[node] = 1;
    q.push(node);
    even[node] = true;
    while(!q.empty()){
        for(int x : adjList[q.front()]){
            if(visited[x] == 0){
                even[x] = (!even[q.front()]);
                if(even[q.front()]) o++;
                else                e++;
                visited[x] = 1;
                q.push(x);
            }else if(even[x] == even[q.front()]){
                flag = true;
                break;
            }
        }
        if(flag) break;
        q.pop();
    }
    return {o,e};
}

long long pow2(int n){
    if(powerOfTwo[n] != 0)
        return powerOfTwo[n];
    
    if(n%2 == 0){
        powerOfTwo[n/2] = pow2(n/2);
        powerOfTwo[n/2] %= MOD;
        powerOfTwo[n] = powerOfTwo[n/2] * powerOfTwo[n/2];
        powerOfTwo[n] %= MOD;
    }else{
        powerOfTwo[(n-1)/2] = pow2((n-1)/2);
        powerOfTwo[(n+1)/2] = pow2((n+1)/2);
        powerOfTwo[(n-1)/2] %= MOD;
        powerOfTwo[(n+1)/2] %= MOD;
        powerOfTwo[n] = powerOfTwo[(n-1)/2] * powerOfTwo[(n+1)/2];
        powerOfTwo[n] %= MOD;
    }

    return powerOfTwo[n];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    reset(powerOfTwo,300001,0LL);
    powerOfTwo[0] = 1LL;
    powerOfTwo[1] = 2LL;

    int t,n,m,x,y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> adjList[n];
        for(int i=0;i<m;i++){
            cin >> x >> y;
            adjList[x-1].emplace_back(y-1);
            adjList[y-1].emplace_back(x-1);
        }

        int visited[n];
        bool even[n];
        long long sum =1LL;
        int e=0,o=0;
        reset(visited,n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                pair<int,int> val = bfs(adjList,visited,even,n,i);
                if(flag){
                    break;
                }else{
                    sum *= (pow2(val.first)+pow2(val.second))%MOD;
                    sum %= MOD;
                }
            }
        }
        if(!flag){
            cout << sum << endl;
        }else{
            cout << "0\n";
            flag = false;
        }
    }

    return 0;
}