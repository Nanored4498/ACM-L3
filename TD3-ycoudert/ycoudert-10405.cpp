#include<iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	string a, b;
	short T[1001][1001];
	short n, m, i, j;

	while(true) {
		getline(cin, a);
		n = a.size();
		if(n == 0) return 0;
		getline(cin, b);
		m = b.size();
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(a[i] == b[j]) T[i+1][j+1] = 1 + T[i][j];
				else T[i+1][j+1] = max(T[i+1][j], T[i][j+1]);
			}
		}
		cout << T[n][m] << endl;
	}
}