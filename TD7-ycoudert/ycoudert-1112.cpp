#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[101];
int d[101];
int N, E, T, M;

int dij(int s, int t) {
	d[s] = -2;
	for(pair<int, int> vo : v[s]) {
		int a = vo.first;
		if(d[a] == -2) continue;
		int l = vo.second;
		if(d[a] == -1) d[a] = l+t;
		else d[a] = min(d[a], t+l);
	}
	int n = -1, nt = T+1;
	for(int i = 1; i <= N; i++) {
		if(d[i] >= 0 && d[i] < nt) {
			n = i;
			nt = d[i];
		}
	}
	if(n == -1) return 1;
	return 1 + dij(n, nt);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int i, a, b, l;
	for(i = 1; i < 101; i++) d[i] = -1;
	int ntc;
	cin >> ntc;

	while(ntc --> 0) {
		for(i = 1; i <= N; i++) d[i] = -1, v[i].clear();
		cin >> N >> E >> T >> M;
		while(M --> 0) {
			cin >> a >> b >> l;
			v[b].push_back(make_pair(a, l));
		}
		if(ntc > 0) cout << dij(E, 0) << "\n\n";
		else cout << dij(E, 0) << "\n";
	}
	return 0;
}