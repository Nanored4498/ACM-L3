#include <iostream>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int D, R, T;
	while(cin >> D) {
		cin >> R >> T;
		int sum = R+T;
		int s = 0;
		for(int i = 4; i < D+3; i++) s += i;
		int r = s;
		int i = D+3;
		while(s < sum) {
			s += 2*i - D;
			r += i;
			i ++;
		}
		cout << R - r << "\n";
	}

	return 0;
}