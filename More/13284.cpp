#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define VI vector<int>
#define MOD 1000000000

int m[256][256];
void f(int *a, int *b, int *r, int n) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			long long add = a[i];
			add = (add * b[j]) % MOD;
			add = (add * m[i][j]) % MOD;
			r[i] = (r[i] + add) % MOD;
		}
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	//Gen début
	int deb[8][256];
	memset(deb[0], 0, 256 * sizeof(int));
	deb[0][1] = 1;
	int p = 1;
	for(int i = 0; i < 7; i++) {
		memset(deb[i+1], 0, 256 * sizeof(int));
		int np = 2*p;
		for(int j = 0; j < np; j++)
			if(deb[i][j] == 1) {
				deb[i+1][j+np] = 1;
				if(j >= p) deb[i+1][j-p] = 1;
			}
		p = np;
	}

	//Mat et deux lignes
	int sec[8][256];
	for(int i = 0; i < 8; i++)
		memset(sec[i], 0, 256 * sizeof(int));
	for(int i = 0; i < 256; i++)
		for(int j = 0; j < 256; j++) {
			for(int k = 0; k <= i; k++) {
				// cout << i << " " << j << " " << k << " " << ((i - k) & (255 - (i & j))) << "   ----!\n";
				if(((i - k) & (255 - (i & j))) == 0) {
					m[i][j] += 1;
					// cout << i << " " << j << " " << k << "\n"; 
					for(int l = 0; l < 8; l++)
						if(deb[l][i] == 1 && deb[l][j] == 1)
							sec[l][k] += 1;
				}
			}
		}
	// for(int i = 0; i < 256; i++) {
		// for(int j = 0; j < 256; j++) cout << m[i][j] << " ";
		// cout << "\n";
	// }
	// cout << "     -MAT\n";

	long long N, M;
	while(cin >> N) {
		cin >> M;
		if(M == 1) {
			int r = 0;
			for(int i = 0; i < 256; i++) r += deb[N-1][i];
			cout << r << "\n";
			continue;
		}
		int v[60][256];
		memcpy(v[0], deb[N-1], 256 * sizeof(int));
		memcpy(v[1], sec[N-1], 256 * sizeof(int));
		int pN = 1 << N;

		long long h = 2;
		int n = 1;
		while(2*h <= M) {
			memset(v[n+1], 0, 256 * sizeof(int));
			f(v[n], v[n], v[n+1], pN);
			n += 1;
			h *= 2;
		}
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j < pN; j++) cout << v[i][j] << " ";
			cout << "\n";
		}

		int r[256];
		memcpy(r, v[n], 256 * sizeof(int));
		M -= h;
		for(int i = n-1; i >= 0; i--) {
			h /= 2;
			if(M >= h) {
				M -= h;
				int pr[256];
				memcpy(pr, r, 256 * sizeof(int));
				f(pr, v[i], r, pN);
			}
		}
		int res = 0;
		for(int i = 0; i < pN; i++) res = (res + r[i]) % MOD;
		cout << res << "\n";
	}
}