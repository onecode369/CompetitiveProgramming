#include "jumps.h"

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int n;
vector<int> H1;

void init(int N, vector<int> H) {
	n = N;
	for(int x : H)
		H1.emplace_back(x);
}

int minimum_jumps(int A, int B, int C, int D) {
	if(H1[C] < H1[A])	return -1;
	vector<pair<int, int>> srt(n,	(0, 0));
	for(int i=0;i<n;i++)
		srt[i] = make_pair(H1[i],i);
	sort(srt.begin(), srt.end(), greater<pair<int, int>>());
	vector<pair<int, pair<int, int>>> srch(n, make_pair(-1, make_pair(-1, -1)));
	
	return 0;
}
