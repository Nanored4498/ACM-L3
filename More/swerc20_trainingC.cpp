#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define PDI pair<double, int>
#define VI vector<int>
#define lsb(n) (n)&(-(n))

struct Point {
	double x, y;
};

istream& operator>>(istream &stream, Point &a) {
	double x, y;
	cin >> x >> y;
	a = {x, y};
	return stream;
}

void add(VI &t, int i, int v) {
	for(; i < t.size(); i+=lsb(i)) t[i] += v;
}

int query(VI &t, int i) {
	int tot = 0;
	for(; i > 0; i -= lsb(i)) tot += t[i];
	return tot;
}
int query(VI &t, int i, int j) {
	return query(t, j) - query(t, i-1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<Point> ps(N);
	for(int i = 0; i < N; i++) cin >> ps[i];

	vector<PDI> proj1(N), proj2(N);
	double sqrt3 = sqrt(3);
	for(int i = 0; i < N; i++) {
		proj1[i] = {ps[i].x - sqrt3*ps[i].y, i};
		proj2[i] = {-ps[i].x - sqrt3*ps[i].y, i};
	}
	sort(proj1.begin(), proj1.end());
	sort(proj2.begin(), proj2.end());

	vector<int> inv_proj1(N);
	for(int i = 0; i < N; i++) inv_proj1[proj1[i].second] = i;

	long long res = 0;
	vector<int> t(N+1, 0);
	for(PDI &p : proj2) {
		int i = p.second;
		int pos = inv_proj1[i]+1;
		res += N-pos-query(t, pos, N);
		add(t, pos, 1);
	}

	cout << res << "\n";

	return 0;
}