#include <iostream>
#include <vector>

using namespace std;

#define ME 100000

int E, m, root;
vector<int> G[ME];
int rs[ME], ts[ME];
long long fenwick[ME+1];
long long res[ME];
int max_r;

#define LSB(i) ((i) & (-i))

long long sum(int i) {
	long long res = 0;
	while(i > 0) res += fenwick[i], i -= LSB(i);
	return res;
}

void add(int i, long long v) {
	while(i < max_r) fenwick[i] += v, i += LSB(i);
}

void f(int i) {
	add(rs[i], ts[i]);
	int rm = rs[i]-1;
	long long s0 = sum(rm);
	for(int j : G[i]) f(j);
	res[i] = sum(rm) - s0;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	while(cin >> E) {
		for(int i = 0; i < E; i++) G[i].clear();
		max_r = 0;
		for(int i = 0; i < E; i++) {
			cin >> m >> rs[i] >> ts[i];
			if(m == -1) root = i;
			else G[m-1].push_back(i);
			max_r = max(max_r, rs[i]);
		}
		for(int i = 0; i <= max_r; i++) fenwick[i] = 0;
		f(root);
		for(int i = 0; i < E; i++) cout << res[i] << "\n";
	}

	return 0;
}