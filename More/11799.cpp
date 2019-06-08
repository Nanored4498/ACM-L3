#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int N, c, res = 0;
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> c;
			res = max(res, c);
		}
		cout << "Case " << t << ": " << res << "\n";
	}
}