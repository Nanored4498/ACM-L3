#include<iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int N, sum[100][101];
	int i, j, k, pred, diff;
	int res;

	while(cin >> N) {
		res = -127;
		for(i = 0; i < N; i++) {
			sum[i][0] = 0;
			for(j = 1; j <= N; j++) {
				cin >> k;
				sum[i][j] = sum[i][j-1] + k;
			}
		}
		for(i = 0; i < N; i++) {
			for(j = i+1; j <= N; j++) {
				pred = 0;
				for(k = 0; k < N; k++) {
					diff = sum[k][j]-sum[k][i];
					if(pred >= 0) pred += diff;
					else pred = diff;
					res = max(res, pred);
				}
			}
		}
		cout << res << "\n";
	}
}