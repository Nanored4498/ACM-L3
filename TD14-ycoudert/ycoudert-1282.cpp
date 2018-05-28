#include <iostream>
#include <string>

using namespace std;

int fu(string s, string p) {
	int res = 0;
	int pos = 0;
	while((pos = s.find(p, pos)) != string::npos) res += 1, pos += 1;
	return res;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, i, j, k, c = 0;
	string p;
	string f[2];
	long long a[2];
	long long res[2];

	while(cin >> n) {
		cin >> p;
		if(n == 0) {
			cout << "Case " << ++c << ": " << (p == "0" ? "1\n" : "0\n");
			continue;
		}
		if(n == 1) {
			cout << "Case " << ++c << ": " << (p == "1" ? "1\n" : "0\n");
			continue;
		}
		int lp = p.length();
		f[0] = "0", f[1] = "1";
		res[0] = 0, res[1] = 0;
		if(lp == 1) {
			if(p == "0") res[0] = 1;
			else res[1] = 1;
			j = 2;
		} else j = 0;
		for(k = 2; k <= n; k++) {
			i = k % 2;
			if(j < 2) {
				string s = f[1-i];
				f[i] = f[1-i].append(f[i]);
				f[1-i] = s;
				if(f[i].length() < lp) continue;
				res[i] = fu(f[i], p);
				j++;
			} else if(j < 4) {
				string s = f[1-i];
				f[i] = f[1-i].append(f[i]);
				f[1-i] = s;
				int r = fu(f[i], p);
				a[i] = r - res[0] - res[1];
				res[i] = r;
				j ++;
			} else res[i] = res[0] + res[1] + a[i];
		}
		cout << "Case " << ++c << ": " << res[i] << "\n";
	}
	return 0;
}