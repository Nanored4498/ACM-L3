#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge;
vector<Edge> G2[25001];
struct Edge {
	int to;
	bool available, available0;
	int sym;
	int state = -1;
	Edge(int t, bool a, int s): to(t), available0(a), sym(s) {}
	bool is_available(int s) {
		if(state != s) {
			available = available0;
			state = G2[to][sym].state = s;
			G2[to][sym].available = !available;
		}
		return available;
	}
	void set_available(bool a) {
		available = a;
		G2[to][sym].available = !available;
	}
};

int n, m, c;
int starts[1001], dis[25001], seen[25001];
vector<pair<int, int>> G[25001];

bool compd(int i, int j) { return dis[i] < dis[j]; }

int i0, di0;
bool augment_path(int i) {
	if(seen[i] == i0) return false;
	if(i == 1) return true;
	seen[i] = i0;
	for(Edge &no : G2[i]) if(no.is_available(di0) && augment_path(no.to)) {
		no.set_available(false);
		return true;
	}
	return false;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int x, y, t;
	while(cin >> n >> m >> c) {
		// Reading input
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			dis[i] = INT32_MAX;
			seen[i] = -1;
		}
		for(int i = 0; i < m; ++i) {
			cin >> x >> y >> t;
			G[x].emplace_back(y, t);
			G[y].emplace_back(x, t);
		}
		for(int i = 0; i < c; ++i) cin >> starts[i];

		// Dijkstra in G
		priority_queue<pair<int, int>> Q;
		Q.emplace(0, 1);
		dis[1] = 0;
		while(!Q.empty()) {
			int d = -Q.top().first, i = Q.top().second;
			Q.pop();
			if(d > dis[i]) continue;
			G2[i].clear();
			for(const pair<int, int> &p : G[i]) {
				int d2 = d + p.second;
				if(d2 < dis[p.first]) {
					dis[p.first] = d2;
					Q.emplace(-d2, p.first);
				} else if(dis[p.first]+p.second == d) {
					G2[i].emplace_back(p.first, true, G2[p.first].size());
					G2[p.first].emplace_back(i, false, G2[i].size()-1);
				}
			}
		}

		// Max Flow in G2
		int res = 0;
		sort(starts, starts+c, compd);
		for(i0 = 0; i0 < c; ++i0) {
			di0 = dis[starts[i0]];
			if((i0 == 0 || dis[starts[i0-1]] != di0) && (i0 == c-1 || dis[starts[i0+1]] != di0)) {
				++ res;
				continue;
			}
			if(augment_path(starts[i0])) ++res;
		}
		cout << res << "\n";
	}

	return 0;
}