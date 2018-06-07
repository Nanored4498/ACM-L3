#include <iostream>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	char t[101][101];
	bool b[100][100];
	int T, N;
	int i, j, k, a, res;
	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
		cin >> N;
		for(i = 0; i < N; i++)
			cin >> t[i];
		res = 0;
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(b[i][j])	b[i][j] = false;
				else if(t[i][j] != '.') {
					a = t[i][j] == '@' ? 1 : 0;
					for(k = i+1; k < N && t[k][j] != '.'; k++) a *= t[k][j] == '@' ? 1 : 0, b[k][j] = true;
					for(k = j+1; k < N && t[i][k] != '.'; k++) a *= t[i][k] == '@' ? 1 : 0, b[i][k] = true;
					res += 1-a;
				}
			}
		}
		cout << "Case " << tc << ": " << res << "\n";
	}
}