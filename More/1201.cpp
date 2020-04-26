#include <iostream>
#include <vector>

using namespace std;

int h[500], h2[500], x[500], y[500], x2[500], y2[500];
int pred[500], last[500];
vector<int> G[500];

bool augment(int i, int pass) {
	if(last[i] == pass) return false;
	last[i] = pass;
	for(int j : G[i])
		if(pred[j] < 0 || augment(pred[j], pass)) {
			pred[j] = i;
			return true;
		}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	char c;
	cin >> N;
	while(N-->0) {
		cin >> M;
		for(int i = 0; i < M; ++i) {
			h[i] = 0;
			cin >> c;
			h[i] += 600 * (c - '0');
			cin >> c;
			h[i] += 60 * (c - '0');
			cin >> c;
			cin >> c;
			h[i] += 10 * (c - '0');
			cin >> c;
			h[i] += (c - '0');
			cin >> x[i] >> y[i] >> x2[i] >> y2[i];
			G[i].clear();
			h2[i] = h[i] + std::abs(x2[i] - x[i]) + std::abs(y2[i] - y[i]);
			for(int j = 0; j < i; ++j)
				if(h2[j] + std::abs(x[i] - x2[j]) + std::abs(y[i] - y2[j]) < h[i])
					G[j].push_back(i);
			pred[i] = last[i] = -1;
		}
		int res = M;
		for(int i = 0; i < M; ++i) if(augment(i, i)) --res;
		cout << res << "\n";
	}

	return 0;
}