#include<iostream>

using namespace std;

long pgcd(long a, long b) {
	if(b == 0) return a;
	else return pgcd(b, a%b);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int t, c, i, j;
	long ai, sa, ma10, res;

	cin >> t;
	while(t > 0) {
		cin >> c;
		res = 0;
		ma10 = 0;
		while(c > 0) {
			sa = 0;
			for(j = 0; j < 9; j++) {
				cin >> ai;
				sa += ai;
			}
			cin >> ai;
			ma10 = max(ma10, ai);
			res = pgcd(sa-ai, res);
			c --;
		}
		if(res > max(ma10, (long)1)) cout << res << "\n";
		else cout << "impossible\n";
		t --;
	}

	return 0;
}
