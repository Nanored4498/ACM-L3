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

	int T;
	int n , m, i, j, res, s = 0;
	int A[100], B[100];
	cin >> T;
	
	for(int t = 1; t <= T; t++) {
		for(i = 0; i < s; i++) v[i].clear();
		cin >> n;
		for(i = 0; i < n; i++) cin >> A[i];
		cin >> m;
		s = n+m;
		for(i = 0; i < m; i++) cin >> B[i];
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(A[i] != 0) {
					if(B[j] % A[i] == 0) v[i].push_back(j + n);
				} else if(B[j] == 0) v[i].push_back(j + n);
		res = 0;
		for(i = n; i < s; i++) pred[i] = -1;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) see[j] = false;
			res += f(i);
		}
		cout << "Case " << t << ": " << res << "\n";
	}
	return 0;
}