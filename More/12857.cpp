#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MN 100
#define MD 18
#define EDGE pair<int, int>
#define VE vector<EDGE>
#define VI vector<int>

VI tree[2*MN];
bool seen[2*MN];
VI part[2];

void dfs(int i, int col) {
	if(seen[i]) return;
	seen[i] = true;
	part[col].push_back(i);
	for(int j : tree[i])
		dfs(j, 1-col);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int N, N2, d;
	string names[2*MN];
	VE de[MD+1];
	int ds[2*MN][2*MN];
	while(cin >> N) {
		N2 = 2*N;
		for(int i = 0; i <= MD; i++)
			de[i].clear();
		part[0].clear(), part[1].clear();
		for(int i = 0; i < N2; i++) {
			cin >> names[i];
			tree[i].clear();
			seen[i] = false;
		}
		for(int i = 0; i < N2; i++) {
			ds[i][i] = 0;
			for(int j = i+1; j < N2; j++) {
				d = 0;
				while(names[i][d] == names[j][d]) d ++;
				d ++;
				de[d].push_back({i, j});
				ds[i][j] = ds[j][i] = d;
			}
		}
		d = MD;
		int n = 1, i = de[d].size();
		UF uf(N2);
		//cout << "test" << endl;
		while(n < N2) {
			while(i == 0)
				i = de[--d].size();
			EDGE e = de[d][--i];
			int a = e.first, b = e.second;
			if(uf.connected(a, b))
				continue;
			tree[a].push_back(b);
			tree[b].push_back(a);
			uf.merge(a, b);
			n ++;
		}
		//cout << "test2" << endl;
		dfs(0, 0);
		int res = 0;
		for(int p = 0; p < 2; p++) {
			for(int i : part[p]) {
				int l = 1;
				for(int j : part[p])
					l = max(l, ds[i][j]);
				res += l;
			}
		}
		cout << res * N << "\n";
	}
	return 0;
}