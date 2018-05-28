#include <iostream>

using namespace std;

// 0 deletion  -  1 insertin  - 2 modification  -  3 good
int d[81][81], p[81][81];

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, m, i, j, k;
	int x, y, z;
	bool e, s = false;

	while(true) {
		string a, b;
		getline(cin, a);
		if(a.length() < 1) return 0;
		getline(cin, b);
		n = a.length();
		m = b.length();
		for(i = 1; i <= n; i++) d[i][0] = i, p[i][0] = 0;
		for(i = 1; i <= m; i++) d[0][i] = i, p[0][i] = 1;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				e = a[i-1] == b[j-1];
				x = 1 + d[i-1][j]; // deletion
				y = 1 + d[i][j-1]; // insertion
				z = e ? d[i-1][j-1] : 1 + d[i-1][j-1]; // good  /  modification
				if(x < z) {
					if(x < y) d[i][j] = x, p[i][j] = 0;
					else d[i][j] = y, p[i][j] = 1;
				} else {
					if(z < y) d[i][j] = z, p[i][j] = e ? 3 : 2;
					else d[i][j] = y, p[i][j] = 1;
				}
			}
		}
		if(s) cout << "\n";
		else s = true;
		cout << d[n][m] << "\n";
		i = n, j = m, k = 1;
		while(i != 0 || j != 0) {
			switch(p[i][j]) {
				case 0: cout << k++ << " Delete " << i-- << "\n";
						break;
				case 1: cout << k++ << " Insert " << i+1 << "," << b[--j] << "\n";
						break;
				case 2: cout << k++ << " Replace " << i-- << "," << b[--j] << "\n";
						break;
				default: i--; j--;
						 break;
			}
		}
	}
}