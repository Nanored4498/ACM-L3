#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long
#define INF 3000000000

struct Edge {
	int to, ind;
	long long w;
};

int N, M;
vector<vector<Edge>> G;

bool seen[4000];
LL augment(int i, LL flow) {
	if(i == 2*N-1) return flow;
	seen[i] = true;
	for(Edge &e : G[i]) {
		if(seen[e.to] || e.w == 0) continue;
		LL f = min(flow, e.w);
		LL a = augment(e.to, f);
		if(a > 0) {
			e.w -= a;
			G[e.to][e.ind].w += a;
			return a;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<pair<LL, int>> P;
	LL p;
	G = vector<vector<Edge>>(2*N);
	for(int i = 0; i < N; i++) {
		cin >> p;
		if(p == -1) p = INF;
		else {
			P.push_back({p, i});
			p = 1;
		}
		Edge e0 = {2*i+1, 0, p};
		Edge e1 = {2*i, 0, 0};
		G[2*i].push_back(e0);
		G[2*i+1].push_back(e1);
	}
	int a, b;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		Edge e0 = {2*b, (int) G[2*b].size(), INF};
		Edge e1 = {2*a+1, (int) G[2*a+1].size(), 0};
		G[2*a+1].push_back(e0);
		G[2*b].push_back(e1);
	}

	sort(P.begin(), P.end());
	LL res = INF;
	for(int k = P.size()-1; k >= 0; k--) {
		for(int i = 0; i < 2*N; i++) seen[i] = false;
		LL a = INF;
		while(a > 0)
			a = augment(0, INF);
		LL flow = G[2*N-1][0].w;
		if(flow > N) break;
		res = min(res, P[k].first * flow);
		G[2*P[k].second][0].w = INF;
	}
	if(res == INF) res = -1;

	cout << res << "\n";

	return 0;
}