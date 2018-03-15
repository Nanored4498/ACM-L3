#include <iostream>
#include <vector>

using namespace std;

int res[1000];
vector<int> m[1000];
int file[1000];
int f, P;

void pl(int x) {
	int n = res[x];
	for(int v : m[x])
		if(res[v] == -1) {
			res[v] = n+1;
			file[f++] = v;
		}
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int N, D;
	int i, a, b;
	file[0] = 0;
	cin >> N;

	while(N > 0) {
		cin >> P >> D;
		m[0].clear();
		for(i = 1; i < P; i++) {
			res[i] = -1;
			m[i].clear();
		}
		f = 1;
		for(i = 0; i < D; i++) {
			cin >> a >> b;
			m[a].push_back(b);
			m[b].push_back(a);
		}
		for(i = 0; i < P-1; i++) {
			pl(file[i]);
		}
		for(i = 1; i < P; i++) {
			cout << res[i] << "\n";
		}
		if(N > 1) cout << "\n";
		N --;
	}
	return 0;
}