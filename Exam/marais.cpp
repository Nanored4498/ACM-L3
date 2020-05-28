#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, L;
	while(cin >> H >> L) {
		vector<string> m(H);
		pii p0;
		for(int i = 0; i < H; ++i) {
			cin >> m[i];
			for(int j = 0; j < L; ++j) if(m[i][j] == 'G') p0 = {i, j};
		}
		vector<pii> q, q2;
		q.push_back(p0);
		vector<vi> ds(H, vi(L, -1));
		ds[p0.first][p0.second] = 0;
		int d = 0, res = 0;
		while(!q.empty()) {
			q2.clear();
			for(int i = 0; i < q.size(); ++i) {
				int x = q[i].first, y = q[i].second;
				if(m[x][y] == 'T') {
					res = d;
					q2.clear();
					break;
				}
				vector<pii> test;
				if(x > 0) test.emplace_back(x-1, y);
				if(x+1 < H) test.emplace_back(x+1, y);
				if(y > 0) test.emplace_back(x, y-1);
				if(y+1 < L) test.emplace_back(x, y+1);
				for(const pii &p : test) if(ds[p.first][p.second] < 0) {
					if(m[p.first][p.second] == 'X') {
						ds[p.first][p.second] = d+1;
						q2.push_back(p);
					} else {
						ds[p.first][p.second] = d;
						q.push_back(p);
					}
				}
			}
			++ d;
			swap(q, q2);
		}
		cout << res << "\n";
	}

	return 0;
}