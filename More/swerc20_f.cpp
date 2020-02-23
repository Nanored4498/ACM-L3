#include <iostream>
#include <vector>

using namespace std;

#define LL long long
#define Point pair<long long, long long>

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, P;
	cin >> N;
	long long res = 0;
	for(int k = 0; k < N; k++) {
		cin >> P;
		vector<Point> ps;
		LL x, y;
		for(int i = 0; i < P; i++) {
			cin >> x >> y;
			ps.emplace_back(x, y);
		}
		LL ar = 0;
		for(int i = 0; i < P; i++) {
			Point a = ps[i], b = ps[(i+1)%P];
			ar += a.first * b.second - a.second * b.first;
		}
		res += abs(ar);
	}
	res >>= 1;
	cout << res << "\n";

	return 0;
}