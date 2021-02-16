#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1e9+7
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)

using namespace std;

map<int,int> extra;
int l = 0;

int minEdgeFnc(vector<int>* adjList,int* visited){
    int cnt = 0;
    visited[0] = 1;
    queue<int> q;
    for(int x : adjList[0]){
        if(visited[x] == 0){
            extra[x] = 1;
            l++;
            visited[x] = 1;
            cnt++;
            q.push(x);
            while(!q.empty()){
                for(int y : adjList[q.front()]){
                    if(visited[y] == 0){
                        visited[y] = 1;
                        q.push(y);
                    }
                }
                q.pop();
            }
        }else{
            extra[x] = 0;
        }
    }
    return cnt;
}

void bfs(vector<int>* adjList,int* visited,int d){
    visited[0] = 1;
    queue<int> q;
    int cnt = (d < l) ? 0 : (d-l); 
    int cnt1 = 0;
    q.push(0);
    while(!q.empty()){
        for(int x : adjList[q.front()]){
            if(q.front() == 0 && extra[x] == 0 && cnt == 0) continue;
            else if(q.front() == 0 && extra[x] == 0 && cnt != 0) cnt--; 
            if(visited[x] == 0){
                cnt1++;
                visited[x] = 1;
                cout << q.front()+1 << " " << x+1 << endl;
                q.push(x);
            }
        }
        q.pop();
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,d,x,y;
    cin >> n >> m >> d;
    vector<int> adjList[n];
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adjList[x-1].emplace_back(y-1);
        adjList[y-1].emplace_back(x-1);
    }

    int visited[n];
    reset(visited,n,0);
    int minEdge = minEdgeFnc(adjList,visited);
    int maxEdge = adjList[0].size();

    if(d < minEdge || d > maxEdge)  cout << "NO\n";
    else{
        cout << "YES\n";
        reset(visited,n,0);
        bfs(adjList,visited,d);
    }

    return 0;
}