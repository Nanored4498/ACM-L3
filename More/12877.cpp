#include <iostream>

using namespace std;

int n;
int l2d[26];
bool used[10];
int w[10][11];

int f(int i, int j, int s) {
	if(i == n-1) {
		int q = s/10, r = s%10;
		bool ur = false;
		if(w[i][j+1] < 0 && (r == 0 || q > 0)) return 0;
		if(l2d[w[i][j]] < 0) {
			if(used[r]) return 0;
			used[r] = true;
			l2d[w[i][j]] = r;
			ur = true;
		} else if(l2d[w[i][j]] != s%10) return 0;
		int res;
		if(w[i][j+1] < 0) {
			res = 1;
		} else {
			int i2 = 0;
			while(w[i2][j+1] < 0) ++i2;
			res = f(i2, j+1, s/10);
		}
		if(ur) {
			used[r] = false;
			l2d[w[i][j]] = -1;
		}
		return res;
	} else {
		int i2 = i+1;
		while(w[i2][j] < 0) ++i2;
		if(l2d[w[i][j]] >= 0) {
			if(w[i][j+1]<0 && l2d[w[i][j]]==0) return 0;
			return f(i2, j, s+l2d[w[i][j]]);
		}
		int res = 0;
		for(int d = w[i][j+1]<0 ? 1 : 0; d < 10; ++d) if(!used[d]) {
			used[d] = true;
			l2d[w[i][j]] = d;
			res += f(i2, j, s+d);
			l2d[w[i][j]] = -1;
			used[d] = false;
		}
		return res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 0; i < 10; ++i) used[i] = false;
	for(int i = 0; i < 26; ++i) l2d[i] = -1;

	while(cin >> n) {
		string s;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			for(int j = 0; j < s.size(); ++j) w[i][j] = s[s.size()-1-j]-'A';
			for(int j = s.size(); j <= 10; ++j) w[i][j] = -1;
		}
		cout << f(0, 0, 0) << "\n";
	}

	return 0;
}