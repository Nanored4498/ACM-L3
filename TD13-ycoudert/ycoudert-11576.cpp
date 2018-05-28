#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, k, k2, w, r, i, j;
	char a[201], c;
	int d[201];
	d[1] = 0;

	cin >> n;
	while(n --> 0) {
		cin >> k >> w;
		cin >> (a+k);
		r = k;
		k2 = 2*k;
		while(--w > 0) {
			c = a[k];
			cin >> a;
			a[k] = c;
			for(i = 1; i < k2; i++) {
				j = d[i];
				while(j >= k || (a[j] != a[i] && j > 0)) j = d[j];
				if(a[j] == a[i]) d[i+1] = j + 1;
				else d[i+1] = 0;
			}
			r += k - min(d[k2], k);
			for(i = 0; i < k; i++) a[i+k] = a[i];
		}
		cout << r << "\n";
	}
	return 0;
}