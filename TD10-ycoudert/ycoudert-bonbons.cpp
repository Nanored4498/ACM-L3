#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	while(true) {
		int N;
		cin >> N;
		if(N-- == 0) return 0;
		int s, m = 0, a;
		cin >> s;
		int r = max(s, -1);
		while(N --> 0) {
			cin >> a;
			s += a;
			r = max(s-m, r);
			m = min(m, s);
		}
		if(r < 0) cout << "Loose.\n";
		else cout << "Winning with " << r << ".\n";
	}
}