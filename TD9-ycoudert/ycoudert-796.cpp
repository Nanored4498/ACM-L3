#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> resu;

vector<int> f(int a, int p, bool *cyc, bool *seen, vector<int> *v) {
	if(cyc[a]) return (vector<int>) {a};
	cyc[a] = true;
	vector<int> res;
	for(int b : v[a]) {
		if(b == p || seen[b]) continue;
		vector<int> r = f(b, a, cyc, seen, v);
		if(r.empty()) {
			if(a > b) resu.push_back({b, a});
			else resu.push_back({a, b});
		} else {
			for(int c : r)
				if(c != a) res.push_back(c);
		}
	}
	cyc[a] = false;
	seen[a] = true;
	return res;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, i, j, a, b, m;
	char c;

	while(cin >> n) {
		vector<int> v[n];
		bool cyc[n], seen[n];
		for(int i = 0; i < n; i ++) cyc[i] = seen[i] = false;
		resu.clear();
		for(i = 0; i < n; i++) {
			cin >> a >> c >> m >> c;
			for(j = 0; j < m; j++) {
				cin >> b;
				v[a].push_back(b);
			}
		}
		for(i = 0; i < n; i++)
			if(!cyc[i]) f(i, i, cyc, seen, v);
		sort(resu.begin(), resu.end());
		cout << resu.size() << " critical links\n";
		for(pair<int, int> p : resu)
			cout << p.first << " - " << p.second << "\n";
		cout << "\n";
	}

	return 0;
}