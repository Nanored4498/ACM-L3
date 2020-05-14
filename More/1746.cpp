#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int a[100];
	int n;
	while(cin >> n) {
		int s = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			s += a[i];
		}
		if(s % 2 == 1) {
			cout << "no quotation\n";
			continue;
		}
		int k = 0;
		while((k+2)*(k+1) <= s) ++k;
		while(k > 0) {
			int i = 0, j = n-1;
			int ai = a[0], aj = a[n-1];
			bool ok = true;
			for(int l = k; l > 1; --l) {
				while(ai == 0) ai = a[++i];
				if(l > ai) { ok = false; break; }
				ai -= l;
				while(aj == 0) { aj = a[--j]; }
				if(l > aj) { ok = false; break; }
				aj -= l;
			}
			if(ok) break;
			--k;
		}
		if(k == 1 && s > 2) cout << "no quotation\n";
		else cout << k << "\n";
	}

	return 0;
}