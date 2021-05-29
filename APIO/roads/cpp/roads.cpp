#include "roads.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#define  INF INT_MAX

using namespace std;

vector<long long> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
	vector<pair<int, pair<int, int>>> road;
	for(int i=0;i<N;i++)
		road.emplace_back(make_pair(W[i], make_pair(U[i], V[i])));
	sort(road.begin(), road.end(), greater<pair<int, pair<int, int>>>());
	vector<int> connected_to(N, 0);
	vector<long long> ans(N+1, 0LL);
	long long tsum = 0LL;
	for(int i=0;i<N;i++)
		tsum += W[i];
	ans.emplace_back(tsum);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(road[j].first != INF){
				if(connected_to[road[j].second.first] <= j && connected_to[road[j].second.second] <= j){
					connected_to[road[j].second.first]++;
					connected_to[road[j].second.second]++;
					tsum -= road[j].first;
					road[j].first = INF;
				}
			}
		}
		ans.emplace_back(tsum);
	}
	return ans;
}
