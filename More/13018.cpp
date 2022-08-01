#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	bool first = true;
	while(cin >> n >> m) {
		if(first) first = false;
		else cout << '\n';
		if(n > m) swap(n, m);
		for(int i = n; i <= m; ++i) cout << i+1 << '\n';
	}

	return 0;
}