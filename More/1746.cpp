#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int a[100];
	int d[100][100];
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i) {
			d[i][i] = 0;
			int f = 1;
			while(2*f <= a[i]) { ++d[i][i]; f *= d[i][i]+1; }
		}
		for(int s = 1; s < n; ++s) {
			for(int i = 0; i < n; ++i) {

			}
		}
	}

	return 0;
}