#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;

bool see[100];
int pred[200];
V v[200];

int f(int x) {
	if(see[x]) return 0;
	see[x] = true;
	for(int y : v[x]) {
		if(pred[y] == -1 || f(pred[y])) {
			pred[y] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int i, j;
	float l[100][2], t[100][2];
	int N, M, S, V;
	cin >> N >> M >> S >> V;
	int s = N + M;
	float dm2 = V*V*S*S;

	for(i = 0; i < N; i++) cin >> l[i][0] >> l[i][1];
	for(i = 0; i < M; i++) cin >> t[i][0] >> t[i][1];
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++) {
			float dx = l[i][0] - t[j][0];
			float dy = l[i][1] - t[j][1];
			if(dx*dx + dy*dy <= dm2)
				v[i].push_back(j + N);
		}
	
	int res = 0;
	for(i = N; i < s; i++) pred[i] = -1;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) see[j] = false;
		res += f(i);
	}
	cout << (N - res) << "\n";
	return 0;
}