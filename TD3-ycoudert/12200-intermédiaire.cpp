#include<iostream>
#include<iomanip>

using namespace std;

int s[22] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20, 1};
double A[501][501], B[501][501];

double mB(int a, int b) {
	double res = 3-A[a][b-20]-A[a][b-1]-A[a][b-18];
	double su = res;
	for(int i = 0; i < 19; i++) {
		su += A[a][b-s[i]] - A[a][b-s[i+3]];
		if(su > res) res = su;
	}
	return res / 3;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	cout << fixed << setprecision(12);
	int i, j, k;
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 20; j++) {
			A[i][j] = 0.136363636364;
			B[i][j] = 0.909090909091;
		}
	}
	for(i = 20; i < 501; i++) {
		for(j = 0; j <= i; j++) {
			A[i][j] = 20;
			for(k = i-20; k < i; k++)
				A[i][j] -= B[k][j];
			A[i][j] /= 20;
			B[j][i] = mB(j, i);
			if(j < 20) {
				A[j][i] = (20 - 19*B[j][i]) / 20;
				B[i][j] = (3 - 2*A[i][j]) / 3;
			} else {
				A[j][i] = 20;
				for(k = j-20; k < j; k++)
					A[j][i] -= B[k][i];
				A[j][i] /= 20;
				B[i][j] = mB(i, j);
			}
		}
	}
	int n;
	while(cin >> n) {
		if(n == 0) return 0;
		cout << A[n-1][n-1] << " " << B[n-1][n-1] << endl;
	}
}