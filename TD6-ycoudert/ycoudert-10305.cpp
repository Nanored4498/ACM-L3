#include <iostream>
#include <vector>

using namespace std;

bool seen[101];
vector<int> p[101];
int c, n;

void pl(int x) {
	for(int v : p[x])
		if(!seen[v]) pl(v);
	seen[x] = true;
	c++;
	if(c < n) cout << x << " ";
	else cout << x << "\n";
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int m;
	int i, a, b;

	while(cin >> n >> m) {
		if(n == 0) return 0;
		for(i = 1; i <= n; i++) {
			seen[i] = false;
			p[i].clear();
		}
		c = 0;
		for(i = 0; i < m; i++) {
			cin >> a >> b;
			p[b].push_back(a);
		}
		for(int i = 1; i <= n; i++)
			if(!seen[i]) pl(i);
	}
}