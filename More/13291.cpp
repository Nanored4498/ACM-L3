#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, v;
	while(cin >> n) {
		long long A[3] = {0, 0, 0};
		for(int i = 0; i < n; i++) {
			cin >> v;
			A[i % 3] += v;
		}
		long long res[3] = {0, 0, 0};
		for(int i = 0; i < n; i++) {
			cin >> v;
			for(int j = 0; j < 3; j++)
				res[(i+j+2) % 3] += A[j]*v;
		}
		cout << res[0] << " " << res[1] << " " << res[2] << "\n";
	}
	return 0;
}