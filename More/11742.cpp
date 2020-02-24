#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> cons[8];
int pos[8];
int leftp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

int f(int a) {
	if(a == n) return 1;
	int res = 0;
	for(int i = n-a-1; i >= 0; i--) {
		int p = leftp[i];
		bool ok = true;
		for(const auto &co : cons[a]) {
			int q = pos[co.first];
			int c = co.second;
			if(c > 0) {
				if(abs(q-p) <= c) continue;
			} else if(abs(q-p) >= -c) continue;
			ok = false;
			break;
		}
		if(ok) {
			pos[a] = p;
			swap(leftp[i], leftp[n-a-1]);
			res += f(a+1);
			swap(leftp[i], leftp[n-a-1]);
		}
	}
	return res;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c;
	while(true) {
		cin >> n >> m;
		if(n == 0) break;
		for(int i = 0; i < n; i++) cons[i].clear();
		while(m --> 0) {
			cin >> a >> b >> c;
			if(a < b) swap(a, b);
			cons[a].emplace_back(b, c);
		}
		cout << f(0) << "\n";
	}

	return 0;
}