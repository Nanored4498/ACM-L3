#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_P 10000
#define MAX_l 1000
typedef pair<int, int> pi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int P, T, l, a, b;
	vector<pi> G[MAX_P];
	int dist[MAX_P];
	bool seen[MAX_P];
	while(cin >> P >> T) {
		for(int i = 0; i < P; ++i) {
			G[i].clear();
			dist[i] = MAX_P*MAX_l+1;
			seen[i] = false;
		}
		while(T --> 0) {
			cin >> a >> b >> l;
			G[a].emplace_back(b, l);
			G[b].emplace_back(a, l);
		}
		priority_queue<pi, vector<pi>, greater<pi>> Q;
		Q.emplace(0, 0);
		dist[0] = 0;
		while(!Q.empty()) {
			pi p = Q.top(); Q.pop();
			int i = p.second, d = p.first;
			if(d > dist[i]) continue;
			if(i == P-1) break;
			for(const pi &q : G[i]) {
				int j = q.first, dj = d+q.second;
				if(dj < dist[j]) { dist[j] = dj; Q.emplace(dj, j); }
			}
		}
		int res = 0;
		seen[P-1] = true;
		vector<int> stack = {P-1};
		while(!stack.empty()) {
			int i = stack.back(); stack.pop_back();
			for(const pi &p : G[i]) {
				if(dist[p.first] + p.second == dist[i]) {
					res += p.second;
					if(seen[p.first]) continue;
					seen[p.first] = true;
					stack.push_back(p.first);
				}
			}
		}
		res *= 2;
		cout << res << "\n";
	}

	return 0;
}