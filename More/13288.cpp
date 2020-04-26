#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};
inline int dist(const Point &a, const Point &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
inline istream& operator>>(istream &stream, Point &a) {
	int x, y;
	cin >> x >> y;
	a = {x, y};
	return stream;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	while(cin >> N >> M) {
		vector<Point> bs(N), cs(M);
		for(int i = 0; i < N; ++i) cin >> bs[i];
		for(int i = 0; i < M; ++i) cin >> cs[i];
		Point r;
		cin >> r;
		int res = 0;
		for(int i = 0; i < N; ++i) res += dist(r, bs[i]);
		cout << res << "\n";
	}

	return 0;
}