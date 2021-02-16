#include<bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007LL
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

unsigned long long gcd(unsigned long long u, unsigned long long v){
    long long shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned long long t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

long long findPD(vector<long long>* adjList,long long* d,long long p){
    if(adjList[p].size() == 0){
        d[p] = 1LL;
        return 1LL;
    }
    d[p] =  1LL;
    for(long long x : adjList[p]){
        if(d[x] == -1)
            d[x] = findPD(adjList,d,x);
        d[p] = (d[p]*d[x])/gcd(d[x],d[p]);
    }
    d[p] *= adjList[p].size();
    return d[p];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> adjList[n];
    long long p[n],num[n],d[n];
    p[0] = -1LL;
    reset(d,n,-1LL);
    for(long long i=0;i<(n-1);i++){
        cin >> p[i+1];
        adjList[p[i+1]-1].emplace_back(i+1);
    }
    findPD(adjList,d,0);
    long long t;
    cin >> t;
    long long node,numTask,left = 0;
    while(t--){
        left = 0LL;
        cin >> node >> numTask;
        queue<long long> q;
        q.push(--node);
        num[node] = numTask;
        while(!q.empty()){
            long long y = q.front();
            if(d[y] < 0){
                left += num[y];
            }else if(num[y]%d[y] != 0){
                if((adjList[y].size() > 0) && num[y]%adjList[y].size() != 0){
                    left += num[y];
                }else{
                    for(long long x : adjList[y]){
                        num[x] = num[y]/adjList[y].size();
                        q.push(x);
                    }
                }
            }
            q.pop();
        }
        cout << left << endl;
    }

    return 0;
}