#include <iostream>

using namespace std;

#define L 101

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int d[L];
	int t = 1;
	char a[L+1], b[L+1];
	cin.getline(a, L);
	while(a[0] != '#') {
		cin.getline(b, L);
		int na, pred, j;
		for(na = 0; a[na] != 0; ++na) d[na] = 0;
		d[na] = 0;
		for(int i = 0; b[i] != 0; ++i) {
			pred = 0;
			for(j = 0; j < na; ++j) {
				int p = pred;
				pred = d[j+1];
				if(b[i] == a[j]) d[j+1] = max(d[j+1], max(d[j], 1+p));
				else d[j+1] = max(d[j+1], d[j]);
			}
		}
		cout << "Case #" << t << ": you can visit at most " << d[na] << " cities.\n";
		cin.getline(a, L);
		++ t;
	}

	return 0;
}