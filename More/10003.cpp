#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int l, n, c;
	vector<int> cs;
	int m[51][51];
	for(int i = 0; i < 50; i++) m[i][i+1] = 0;
	while(true) {
		cin >> l >> n;
		if(l == 0) return 0;
		cs.clear();
		cs.push_back(0);
		for(int i = 0; i < n; i++) {
			cin >> c;
			cs.push_back(c);
		}
		cs.push_back(l);
		for(int l2 = 2; l2 <= n+1; l2++) {
			for(int i = 0; i < n+2-l2; i++) {
				int best = 50000;
				for(int j = i+1; j < i+l2; j++) {
					int cost = m[i][j] + m[j][i+l2];
					best = min(best, cost);
				}
				m[i][i+l2] = best + cs[i+l2] - cs[i];
			}
		}
		cout << "The minimum cutting is " << m[0][n+1] << ".\n";
	}
}