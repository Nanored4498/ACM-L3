#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int p10[8], pos[4][2];
	p10[0] = 1;
	for(int i = 1; i < 8; ++i) p10[i] = 10*p10[i-1];

	int n, w, h, l, xi, xj;
	while(cin >> n) {
		cin >> w >> h >> l;
		unordered_set<int> seen;
		vector<int> to_see, ts2;
		int s0 = 0;
		string m[10];
		for(int i = 0; i < h; ++i) {
			cin >> m[i];
			for(int j = 0; j < w; ++j)
				if(m[i][j] - '1' < 4) {
					s0 += i * p10[2*(m[i][j]-'1')] + j * p10[2*(m[i][j]-'1')+1];
					m[i][j] = '.';
				} else if(m[i][j] == 'X') { xi = i; xj = j; }
		}
		int d = 0, res = -1;
		to_see.push_back(s0);
		seen.insert(s0);
		while(d < l && !to_see.empty()) {
			++ d;
			ts2.clear();
			for(int s : to_see) {
				int ss = s;
				for(int p = 0; p < n; ++p) {
					pos[p][0] = ss % 10; ss /= 10;
					pos[p][1] = ss % 10; ss /= 10;
					m[pos[p][0]][pos[p][1]] = 'W';
				}
				for(int p = 0; p < n; ++p) {
					int i = pos[p][0], j = pos[p][1];
					if(i > 0 && m[i-1][j] != 'W') {
						while(i > 0 && m[i-1][j] != 'W') --i;
						if(p == 0 && m[i][j] == 'X') { res = d; break; }
						int s2 = s + (i - pos[p][0]) * p10[2*p];
						if(!seen.count(s2)) {
							seen.insert(s2);
							ts2.push_back(s2);
						}
						i = pos[p][0];
					}
					if(i+1 < h && m[i+1][j] != 'W') {
						while(i+1 < h && m[i+1][j] != 'W') ++i;
						if(p == 0 && m[i][j] == 'X') { res = d; break; }
						int s2 = s + (i - pos[p][0]) * p10[2*p];
						if(!seen.count(s2)) {
							seen.insert(s2);
							ts2.push_back(s2);
						}
						i = pos[p][0];
					}
					if(j > 0 && m[i][j-1] != 'W') {
						while(j > 0 && m[i][j-1] != 'W') --j;
						if(p == 0 && m[i][j] == 'X') { res = d; break; }
						int s2 = s + (j - pos[p][1]) * p10[2*p+1];
						if(!seen.count(s2)) {
							seen.insert(s2);
							ts2.push_back(s2);
						}
						j = pos[p][1];
					}
					if(j+1 < w && m[i][j+1] != 'W') {
						while(j+1 < w && m[i][j+1] != 'W') ++j;
						if(p == 0 && m[i][j] == 'X') { res = d; break; }
						int s2 = s + (j - pos[p][1]) * p10[2*p+1];
						if(!seen.count(s2)) {
							seen.insert(s2);
							ts2.push_back(s2);
						}
					}
				}
				if(res >= 0) break;
				for(int p = 0; p < n; ++p) m[pos[p][0]][pos[p][1]] = '.';
				m[xi][xj] = 'X';
			}
			if(res >= 0) break;
			swap(to_see, ts2);
		}
		if(res < 0) cout << "NO SOLUTION\n";
		else cout << res << "\n";
	}

	return 0;
}