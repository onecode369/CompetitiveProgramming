#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " " << x << endl

using namespace std;

void bfs(vector<int>* adjList,int* visited,int* minDis,int x,int y){
	visited[x] = 1;
	minDis[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		for(int v : adjList[q.front()]){
			if(visited[v] == 0){
				visited[v] = 1;
				q.push(v);
				minDis[v] = minDis[q.front()] + 1;
			}
		}
		q.pop();
	}
}

void makeATree(vector<int>* adjList,int* primeList,int x = 1009){
	if(adjList[x].size() != 0){
		return;
	}
	int num1,num2,num3,num4;
	for(int i=0;i<10;i++){
		if(i != 0){
			num1 = i*1000 + (x%1000);
			if(primeList[num1] == 1 && num1 != x){
				adjList[x].push_back(num1);
				makeATree(adjList,primeList,num1);
			}
		}
		num2 = (x/1000)*1000 + i*100 + (x%100);
		num3 = (x/1000)*1000 + ((x%1000)/100)*100 + i*10 + (x%10);
		num4 = (x/1000)*1000 + ((x%1000)/100)*100 + ((x%100)/10)*10 + i;
		if(primeList[num2] == 1 && num2 != x){
			adjList[x].push_back(num2);
			makeATree(adjList,primeList,num2);
		}
		if(primeList[num3] == 1 && num3 != x){
			adjList[x].push_back(num3);
			makeATree(adjList,primeList,num3);
		}
		if(primeList[num4] == 1 && num4 != x){
			adjList[x].push_back(num4);
			makeATree(adjList,primeList,num4);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int primeList[10000];

	for(int i=0;i<10000;i++)	primeList[i] = 1;

	primeList[0] = primeList[1] = 0;
	for(int i=2;i<10000;i++){
		if(primeList[i] == 1){
			for(int j=i*2;j<10000;j+=i){
				primeList[j] = 0;
			}
		}
	}

	vector<int> adjList[10000];

	makeATree(adjList,primeList);

	int t,x,y;
	cin >> t;

	while(t--){
		cin >> x >> y;
		int visited[10000] = {0};
		int minDis[10000] = {0};
		bfs(adjList,visited,minDis,x,y);

		if(visited[y] == 1){
			cout << minDis[y] << endl;
		}else{
			cout << "Impossible\n";
		}
	}

	return 0;
}