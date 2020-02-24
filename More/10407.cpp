#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(a == 0) return b;
	while(b != 0) {
		int mod = a%b;
		a = b;
		b = mod;
	}
	return a;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a[1000];
	while(true) {
		int n = 0, v;
		while(true) {
			cin >> v;
			if(v == 0) break;
			a[n++] = v;
		}
		if(n == 0) break;
		int res = a[1] - a[0];
		for(int i = 2; i < n; i++)
			res = gcd(res, a[i]-a[i-1]);
		cout << abs(res) << "\n";
	}

	return 0;
}