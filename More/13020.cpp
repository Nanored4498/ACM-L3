#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define MAX_N 50
#define get(a, i) a[i.first][i.second]

int N, M, A, B, n, step;
char field[MAX_N][MAX_N];
int ext[MAX_N][MAX_N], seen[MAX_N][MAX_N], dist[MAX_N][MAX_N];
pii order[MAX_N*MAX_N];
int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
vii G[MAX_N][MAX_N];
int opp[MAX_N][MAX_N][4], flow[MAX_N][MAX_N][4];

bool comp(const pii &a, const pii &b) { return dist[a.first][a.second] < dist[b.first][b.second]; }

int dfs(int i, int j, int f) {
	int add = 0;
	seen[i][j] = step;
	if(field[i][j] == '#' && ext[i][j] < B) {
		add = min(f, B-ext[i][j]);
		ext[i][j] += add;
		return add;
	}
	for(int k = 0; k < G[i][j].size(); ++k) {
		int i2 = G[i][j][k].first, j2 = G[i][j][k].second;	
		if(seen[i2][j2] != step && flow[i][j][k] < A) {
			add = dfs(i2, j2, min(f, A - flow[i][j][k]));
			if(add > 0) {
				flow[i][j][k] += add;
				flow[i2][j2][opp[i][j][k]] -= add;
				return add;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> N) {
		cin >> M >> A >> B;
		for(int i = 0; i < N; ++i) cin >> field[i];
		// Init
		n = 0;
		for(int i = 0; i < N; ++i) for(int j = 0; j < M; ++j) {
			dist[i][j] = ext[i][j] = seen[i][j] = 0;
			if(field[i][j] == '.') for(int k = 0; k < 4; ++k) {
				int i2 = i+di[k], j2 = j+dj[k];
				if(i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) continue;
				if(field[i2][j2] == '#') {
					dist[i][j] = 1;
					order[n++] = {i, j};
					break;
				}
			}
		}
		// BFS
		for(int k = 0; k < n; ++k) {
			int i = order[k].first, j = order[k].second;
			for(int l = 0; l < 4; ++l) {
				int i2 = i+di[l], j2 = j+dj[l];
				if(i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) continue;
				if(field[i2][j2] == '.' && dist[i2][j2] == 0) {
					order[n++] = {i2, j2};
					dist[i2][j2] = dist[i][j]+1;
				}
			}
		}
		// Ordered neighborhood
		for(int i = 0; i < N; ++i) for(int j = 0; j < M; ++j) {
			vii &Gij = G[i][j];
			Gij.clear();
			for(int k = 0; k < 4; ++k) {
				int i2 = i+di[k], j2 = j+dj[k];
				if(i2 >= 0 && i2 < N && j2 >= 0 && j2 < M) Gij.emplace_back(i2, j2);
				flow[i][j][k] = 0;
			}
			sort(G[i][j].begin(), G[i][j].end(), comp);
			for(int k = 0; k < G[i][j].size(); ++k) if(Gij[k].first < i || Gij[k].second < j) {
				int l = 0;
				while(get(G, Gij[k])[l].first != i || get(G, Gij[k])[l].second != j) ++l;
				get(opp, Gij[k])[l] = k;
				opp[i][j][k] = l;
			}
		}
		// Max-Flow
		step = 1;
		int res = 0, add;
		do {
			add = 0;
			for(int i = 0; i < n; ++i)
				if(get(seen, order[i]) != step && get(ext, order[i]) < B)
					if((add = dfs(order[i].first, order[i].second, B-get(ext, order[i]))) > 0) {
						get(ext, order[i]) += add;
						break;
					}
			res += add;
			cerr << add << endl;
			++ step;
		} while(add > 0);
		cout << res << "\n";
	}

	return 0;
}