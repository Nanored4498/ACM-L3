#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};
int dist(const Point &a, const Point &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
istream& operator>>(istream &stream, Point &a) {
	int x, y;
	cin >> x >> y;
	a = {x, y};
	return stream;
}

struct Assos {
	int d, i, j;
};
bool operator<(const Assos &a, const Assos &b) {
	return a.d < b.d;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	while(cin >> N >> M) {
		vector<Point> bs(N), cs(M);
		for(int i = 0; i < N; i++) cin >> bs[i];
		for(int i = 0; i < M; i++) cin >> cs[i];
		Point r;
		cin >> r;
		vector<bool> abs(N, true), acs(M, true);
		int res = 0;
		vector<Assos> as;
		int mind = 2000;
		for(int i = 0; i < N; i++) {
			int dr = dist(bs[i], r);
			res += 2*dr;
			for(int j = 0; j < M; j++) {
				int d = dist(bs[i], cs[j]);
				if(d < dr) as.push_back({d-dr, i, j});
				else mind = min(mind, d-dr);
			}
		}
		sort(as.begin(), as.end());
		for(Assos &a : as)
			if(abs[a.i] && acs[a.j]) {
				abs[a.i] = acs[a.j] = false;
				res += a.d;
			}
		if(as.empty()) res += mind;
		cout << res << "\n";
	}

	return 0;
}