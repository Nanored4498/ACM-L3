#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> v[100001];
bool seen[100001];
stack<int> p;

void g(int x) {
	seen[x] = true;
	for(int y : v[x])
		if(!seen[y]) g(y);
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	int n, m, a, b, res;
	cin >> T;

	while(T-- > 0) {
		for(m = 1; m <= n; m++)	seen[m] = false, v[m].clear();
		cin >> n >> m;
		res = 0;
		while(m-- > 0) {
			cin >> a >> b;
			v[a].push_back(b);
		}
		for(m = 1; m <= n; m++)
			if(!seen[m]) g(m), p.push(m);
		for(m = 1; m <= n; m++)	seen[m] = false;
		while(!p.empty()) {
			a = p.top();
			if(!seen[a]) g(a), res ++;
			p.pop();
		}
		cout << res << "\n";
	}
}