#include <iostream>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int m, n, k;
	string grid[50];
	string s;

	while(T --> 0) {
		cin >> m >> n;
		for(int i = 0; i < m; i++) {
			cin >> grid[i];
			for(char &c : grid[i]) c = tolower(c);
		}
		cin >> k;
		for(int i = 0; i < k; i++) {
			cin >> s;
			for(char &c : s) c = tolower(c);
			int ss = s.size();
			for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
				if(grid[i][j] == s[0]) {
					for(int di = -1; di <= 1; di++) for(int dj = -1; dj <= 1; dj++) {
						if(di == 0 && dj == 0) continue;
						int li = i+(ss-1)*di, lj = j+(ss-1)*dj;
						if(li < 0 || li >= m || lj < 0 || lj >= n) continue;
						int a = 0, ai = i, aj = j;
						while(a < ss) {
							if(grid[ai][aj] != s[a]) break;
							a ++, ai += di, aj += dj;
						}
						if(a == ss) {
							cout << i+1 << " " << j+1 << "\n";
							goto found;
						}
					}
				}
			}
			found: ;
		}
		if(T > 0) cout << "\n";
	}

	return 0;
}