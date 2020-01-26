#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	int a[2000], b[2000];
	while(cin >> N) {
		cin >> M;
		for(int i = 0; i < N; i++) cin >> a[i];
		for(int i = 0; i < M; i++) cin >> b[i];
		map<int, int> count;
		int res=0, maxC=0;
		int j0 = 0;
		for(int i = 0; i < N; i++) {
			while(b[j0] <= a[i]) j0 ++;
			for(int j = j0; j < M; j++) {
				int d = b[j] - a[i];
				count[d] += 1;
				if(count[d] > maxC) {
					res = d;
					maxC = count[d];
				} else if(count[d] == maxC) res = min(res, d);
			}
		}
		cout << res << "\n";
	}

	return 0;
}