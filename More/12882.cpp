#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> t3i;
#define MAX_N 50000
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>

int ids[MAX_N], sizes[MAX_N];
ll area[MAX_N];

int find(int i) {
	if(ids[i] != i) ids[i] = find(ids[i]);
	return ids[i];
}

void merge(int i, int j) {
	int ri = find(i), rj = find(j);
	if(ri == rj) return;
	if(sizes[ri] < sizes[rj]) swap(ri, rj);
	sizes[ri] += sizes[rj];
	area[ri] += area[rj];
	ids[rj] = ri;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, x, y, w, h;
	map<int, vector<t3i>> x_adj, y_adj;
	
	while(cin >> N) {
		x_adj.clear();
		y_adj.clear();
		for(int i = 0; i < N; ++i) {
			cin >> x >> y >> w >> h;
			x_adj[x].emplace_back(y, y+h, i);
			x_adj[x+w].emplace_back(y, y+h, i);
			y_adj[y].emplace_back(x, x+w, i);
			y_adj[y+h].emplace_back(x, x+w, i);
			ids[i] = i;
			sizes[i] = 1;
			area[i] = w*h;
		}
		for(auto adj : {x_adj, y_adj}) {
			for(auto &p : adj) {
				vector<t3i> &v = p.second;
				sort(v.begin(), v.end());
				int stone=-1, end=INT32_MIN;
				for(const t3i &t : v) {
					if(g0(t) <= end) {
						merge(stone, g2(t));
						end = max(end, g1(t));
					} else {
						stone = g2(t);
						end = g1(t);
					}
				}
			}
		}
		ll res = 0;
		for(int i = 0; i < N; ++i) res = max(res, area[i]);
		cout << res << "\n";
	}

	return 0;
}