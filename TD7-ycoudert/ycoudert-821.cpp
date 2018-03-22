#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(3);

	int m[101][101];
	bool u[101];
	vector<int> s;
	int i, j, a, b, c;
	double res;

	while(cin >> a >> b) {
		if(a == 0) return 0;
		s.clear();
		for(i = 1; i < 101; i++) {
			u[i] = false;
			for(j = 1; j < 101; j++)
				if(j == i) m[i][j] = 0;
				else m[i][j] = 101;
		}
		do {
			u[a] = u[b] = true;
			m[a][b] = 1;
			cin >> a >> b;
		} while(a > 0);
		for(i = 1; i < 101; i++) if(u[i]) s.push_back(i);
		for(int k : s)
			for(int i : s)
				for(int j : s)
					m[i][j] = min(m[i][j], m[i][k]+m[k][j]);
		res = 0;
		a = s.size();
		for(int i : s)
			for(int j : s)
				if(i != j) res += m[i][j];
		cout << "Case " << (++c) << ": average length between pages = " << res / (a-1) / a << " clicks\n";
	}
}