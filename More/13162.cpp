#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long binom[11][51];
double E[51][11][11][11][11];

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n = 0; n <= 50; n++) {
		binom[0][n] = 1;
		if(n <= 10) binom[n][n] = 1;
		for(int k = 1; k <= min(n-1, 10); k++)
			binom[k][n] = binom[k][n-1] + binom[k-1][n-1];
	}

	for(int n = 1; n <= 50; n++) {
		int ma = min(10, n);
		for(int d = 1; d <= ma; d++) {
			double dpn = pow(binom[d][n], 1.0/4.0);
			for(int c1 = 0; c1 <= ma; c1 ++) {
				int ma2 = min(c1, n-c1);
				for(int c2 = 0; c2 <= ma2; c2 ++) {
					int sc = c1 + c2;
					int ma3 = min(ma-c2, n-sc);
					for(int c12 = 0; c12 <= ma3; c12 ++) {
						int ssc = sc + c12;
						if(ssc == c1 || ssc == c2) {
							E[n][d][c1][c2][c12] = 0;
							continue;
						}
						double self = 0;
						double e = 0;
						int mb1 = min(d, c1);
						for(int a = max(0, d+c1-n); a <= mb1; a++) {
							int db = d-a;
							int mb2 = min(db, c2);
							double pa = binom[a][c1] / dpn;
							for(int b = max(0, db+sc-n); b <= mb2; b++) {
								int dy = db-b;
								int mb3 = min(dy, c12);
								double pb = pa * binom[b][c2] / dpn;
								for(int y = max(0, dy+ssc-n); y <= mb3; y++) {
									double py = pb * binom[y][c12] / dpn;
									int z = dy-y;
									double pz = py * binom[z][n-ssc] / dpn;
									if(z < d) {
										int c1b = c1-a, c2b = c2-b;
										if(c1b >= c2b) e += pz * E[n][d][c1b][c2b][c12-y];
										else e += pz * E[n][d][c2b][c1b][c12-y];
									}
									else self = pz;
								}
							}
						}
						E[n][d][c1][c2][c12] = (e + 1) / (1 - self);
					}
				}
			}
		}
	}

	int N, D, C;
	vector<int> A, B;
	int a;
	while(cin >> N) {
		cin >> D >> C;
		A.clear();
		for(int i = 0; i < C; i++) {
			cin >> a;
			A.push_back(a);
		}
		sort(A.begin(), A.end());
		B.clear();
		for(int i = 0; i < C; i++) {
			cin >> a;
			B.push_back(a);
		}
		sort(B.begin(), B.end());
		int c12=0, i=0, j=0;
		while(i < C && j < C) {
			if(A[i] == B[j]) i ++, j ++, c12 ++;
			else if(A[i] < B[j]) i ++;
			else j++;
		}
		cout << E[N][D][C-c12][C-c12][c12] << "\n";
	}

	return 0;
}