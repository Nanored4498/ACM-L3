#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	long long L[500];
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> L[i];

	long long t[500][500];
	long long s[501];
	s[0] = 0;

	for(int i = 0; i < N; i++) {
		s[i+1] = s[i]+L[i];
		t[i][i] = 0;
	}

	for(int k = 1; k < N; k++) {
		for(int i = 0; i < N-k; i++) {
			long long m = t[i+1][i+k];
			for(int j = i; j < i+k; j++)
				m = min(m, t[i][j]+t[j+1][i+k]);
			t[i][i+k] = m + s[i+k+1] - s[i];
		}
	}

	cout << t[0][N-1] << "\n";

	return 0;
}