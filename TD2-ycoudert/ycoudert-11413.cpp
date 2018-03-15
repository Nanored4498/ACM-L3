#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m;
	long vs[1000];
	long r[2][1000];
	int i, j, k, a, b;
	long e;

	while(cin >> n >> m) {
		for(i = 0; i < n; i++)
			cin >> vs[i];

		r[0][0] = vs[0];
		for(i = 1; i < n; i++)
			r[0][i] = vs[i] + r[0][i-1];

		a = 0;
		for(i = 1; i < m; i++) {
			a = i%2; //la ligne de r à modifier
			b = 1-a; //la ligne de r à lire
			e = 0; //valeur dans le dernier conteneur
			k = i; //indice de début du dernier conteneur
			for(j = i; j < n; j++) {
				e += vs[j];
				while(r[b][k] < e && k < j) {
					e -= vs[k];
					k ++;
				}
				r[a][j] = max(e, r[b][k-1]);
			}
		}

		cout << r[a][n-1] << endl;
	}

	return 0;
}