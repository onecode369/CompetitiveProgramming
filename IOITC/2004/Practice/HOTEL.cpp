#include<bits/stdc++.h>

typedef long long ll;

#define int ll
#define DEBUG(x) cerr << #x << " = " << x << endl
#define MOD 1000000007
#define INF INT_MAX
#define reset(arr,n,i) fill(arr, arr+n, i)
#define iseql(a,b) ((abs(a-b) - 1e-9 < 0) ? 1 : 0)

using namespace std;

void createMinTree(vector<pair<int,queue<int>>>& roomUpkeep, pair<int,int>* minTree, int start, int end, int node){
    if(start == end){
        minTree[node] = {roomUpkeep[start].second.front(), start};
        return;
    }
    int left[2], right[2], mid = (start + end) / 2;
    if(minTree[2*node+1].second == -1)
        createMinTree(roomUpkeep, minTree, start, mid, 2*node+1);
    if(minTree[2*node+2].second == -1)
        createMinTree(roomUpkeep, minTree, mid+1, end, 2*node+2);
    left[0] = minTree[2*node+1].first;
    left[1] = minTree[2*node+1].second;
    right[0] = minTree[2*node+2].first;
    right[1] = minTree[2*node+2].second;
    if(left[0] <= right[0]){
        minTree[node].first = left[0];
        minTree[node].second = left[1];
    }else{
        minTree[node].first = right[0];
        minTree[node].second = right[1];
    }
}

void updateMinTree(pair<int,int>* minTree, int start, int end, int node, int idx, int value){
    if(start == end){
        minTree[node] = {value,start};
        int x = node;
        while(x >= 0){
            x--;
            x /= 2;
            if(minTree[2*x+1].first <= minTree[2*x+2].first)
                minTree[x] = minTree[2*x+1];
            else
                minTree[x] = minTree[2*x+2];
            if(x == 0)  break;
        }
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid)
        updateMinTree(minTree, start, mid, 2*node+1, idx, value);
    else
        updateMinTree(minTree, mid+1, end, 2*node+2, idx, value);
}

pair<int,int> queryMinTree(pair<int,int>* minTree, int start, int end, int node, int left, int right){
    if(start > right || end < left)
        return {INF,-1};
    if(start >= left && end <= right)
        return minTree[node];
    int mid = (start + end) / 2;
    if(mid >= right)    return queryMinTree(minTree, start, mid, 2*node+1, left, right);
    if(mid < left)      return queryMinTree(minTree, mid+1, end, 2*node+2, left, right);
    pair<int,int> leftQuery = queryMinTree(minTree, start, mid, 2*node+1, left, right);
    pair<int,int> rightQuery = queryMinTree(minTree, mid+1, end, 2*node+2, left, right);
    if(leftQuery.first <= rightQuery.first)
        return leftQuery;
    return rightQuery;
}

void solve(){
    int n,m,o;
    cin >> n >> m >> o;
    vector<pair<int,int>>   roomUpkeepInt(n), // No. $$$
                                 roomRent(m); // $$$ No.
    vector<pair<int,queue<int>>> roomUpkeep;
    vector<int> cap;
    for(int i=0;i<n;i++)
        cin >> roomUpkeepInt[i].second >> roomUpkeepInt[i].first;
    for(int i=0;i<m;i++)
        cin >> roomRent[i].first >> roomRent[i].second;
    sort(roomRent.begin(), roomRent.end());
    sort(roomUpkeepInt.begin(), roomUpkeepInt.end());
    long long ans = 0LL,prev=-1;
    for(int i=0;i<n;){
        queue<int> rent;
        prev = roomUpkeepInt[i].first;
        while(prev == roomUpkeepInt[i].first){
            rent.push(roomUpkeepInt[i].second);
            i++;
        }
        cap.emplace_back(prev);
        roomUpkeep.emplace_back(make_pair(prev,rent));
    }
    vector<pair<int,int>>().swap(roomUpkeepInt);
    pair<int,int> minTree[4*n];
    for(int i=0;i<4*n;i++)
        minTree[i].first = minTree[i].second = -1;
    createMinTree(roomUpkeep, minTree, 0, cap.size()-1, 0);
    int x = m-1;
    vector<int> profit;
    while(true){
        auto lower = lower_bound(cap.begin(), cap.end(), roomRent[x].second);
        int p = lower - cap.begin();
        if(p < (ll) cap.size()){
            pair<int,int> minn = queryMinTree(minTree, 0, cap.size()-1, 0, p, cap.size()-1);
            int minpos = minn.second,minval = minn.first;
            if(minpos == -1)    break;
            if((roomUpkeep[minpos].second.size() > 0) && (roomRent[x].first-minval > 0)){
                profit.emplace_back(roomRent[x].first-minval);
                roomUpkeep[minpos].second.pop();
                if(roomUpkeep[minpos].second.size() == 0)
                    updateMinTree(minTree,0,cap.size()-1,0,minpos,INF);
                else
                    updateMinTree(minTree,0,cap.size()-1,0,minpos,roomUpkeep[minpos].second.front());
            }
        }
        x--;
        if(x < 0)   break;
    }
    sort(profit.begin(), profit.end());
    for(int i=1;i<=o && i <= (ll) profit.size();i++)
        ans += profit[profit.size()-i];
    cout << ans;      
}

signed main(){
    #ifdef ONECODE369
    freopen("input.txt","r", stdin );
    freopen("output.txt","w",stdout);
    freopen("error.txt","w", stderr);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}