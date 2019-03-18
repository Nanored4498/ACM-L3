#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	long long res;
	long long t[3];
	long long buf[3];
	bool init;

	while (cin >> s) {
		res = 0;
		init = false;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] < '0' || s[i] > '9') {
				init = false;
				continue;
			}
			if (!init) {
				for (int j = 0; j < 3; j++)
					t[j] = 0;
				init = true;
			}
			long long m = s[i] - '0';
			for (int j = 0; j < 3; j++)
				buf[j] = t[j];
			for (int j = 0; j < 3; j++)
				t[(j + m) % 3] = buf[j];
			t[m % 3]++;
			res += t[0];
		}
		cout << res << endl;
	}
	return 0;
}
