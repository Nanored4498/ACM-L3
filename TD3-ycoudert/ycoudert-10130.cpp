#include<iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int T, N, P, W;
	int best[31];
	int i, j, res;
	
	cin >> T;
	while(T-- > 0) {
		cin >> N;
		for(i = 0; i < 31; i++) {
			best[i] = 0;
		}
		for(i = 0; i < N; i++) {
			cin >> P >> W;
			for(j = 30; j >= W; j--) {
				best[j] = max(best[j], best[j - W] + P);
			}
		}
		res = 0;
		cin >> N;
		for(i = 0; i < N; i++) {
			cin >> W;
			res += best[W];
		}
		cout << res << endl;
	}
}