#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100000

int mi[3*MAX], ma[3*MAX];

int add(int l, int r, int h, int i, int a, int b) {
	if(l >= b || r <= a) return 0;
	if(h < mi[i]) return 0;
	if(l <= a && b <= r) {
		if(h < ma[i]) {
			int m = (a+b)/2;
			int res = add(l, r, h, 2*i, a, m) + add(l, r, h, 2*i+1, m, b);
			mi[i] = min(mi[2*i], mi[2*i+1]);
			return res;
		} else {
			mi[i] = ma[i] = h;
			return b - a;
		}
	} else {
		if(b > a+1 && mi[i] == ma[i])
			mi[2*i] = ma[2*i] = mi[2*i+1] = ma[2*i+1] = mi[i];
		ma[i] = max(ma[i], h);
		int m = (a+b)/2;
		int res = add(l, r, h, 2*i, a, m) + add(l, r, h, 2*i+1, m, b);
		mi[i] = min(mi[2*i], mi[2*i+1]);
		return res;
	}
}

int main() {
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int c;
	cin >> c;
	int n, l, r, h;
	while(c --> 0) {
		cin >> n;
		mi[1] = 0, ma[1] = 0;
		int res = 0;
		while(n --> 0) {
			cin >> l >> r >> h;
			res += add(l, r, h, 1, 1, MAX);
		};
		cout << res << "\n";
	}

	cin >> c;
	return 0;
}