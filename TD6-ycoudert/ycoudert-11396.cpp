#include <iostream>
#include <vector>

using namespace std;

vector<int> v[301];
int col[301];

bool color(int s, int c) {
	col[s] = c;
	for(int x : v[s])
		if(col[x] == c || (col[x] == 0 && color(x, 3-c))) return true;
	return false;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int V = 0;
	int i, a, b;
	bool bo;

	while(true) {
		for(i = 1; i <= V; i++) col[i] = 0, v[i].clear();
		cin >> V;
		if(V == 0) return 0;
		bo = false;
		while(true) {
			cin >> a >> b;
			if(a == 0) break;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(i = 1; i <= V; i++)
			if(col[i] == 0 && color(i, 1)) {
				bo = true;
				break;
			}
		if(bo) cout << "NO\n";
		else cout << "YES\n";
	}
}