#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int W, N, w, l;
	while(cin >> W) {
		cin >> N;
		int res = 0;
		while(N --> 0) {
			cin >> w >> l;
			res += w*l;
		}
		cout << res / W << "\n";
	}

	return 0;
}