#include<iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int e, x, n;
	long long y;
	long px, res;
	cin >> e;

	while(e > 0) {
		cin >> x >> y >> n;
		e --;
		res = 1;
		px = x;
		while(y > 1) {
			if(y & 1 == 1) res = (res*px) % n;
			px = (px*px) % n;
			y = y >> 1;
		}
		cout << ((res*px)%n) << "\n";
	}
	cin >> e;
	return 0;
}