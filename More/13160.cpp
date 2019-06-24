#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	bool add;
	double frac;
	Point(int x, int y, bool a): add(a) {
		if(y == 0) frac = 9999;
		else frac = - double(x) / double(y);
	}
};

bool operator<(const Point &a, const Point &b) { return a.frac < b.frac; }

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	int x0, y0;
	int x, y;
	vector<Point> ps;
	while(cin >> N) {
		cin >> x0 >> y0;
		int sup = 0;
		int eq = 0;
		ps.clear();
		for(int i = 1; i < N; i++) {
			cin >> x >> y;
			if(x > x0) {
				sup ++;
				if(y <= y0) ps.emplace_back(x-x0, y-y0, false);
			} else if(x == x0) {
				if(y == y0) {
					eq ++;
					continue;
				}
				if(y < y0) sup ++;
				ps.emplace_back(0, y-y0, y > y0); 
			} else if(y >= y0) ps.emplace_back(x-x0, y-y0, true);
		}
		sort(ps.begin(), ps.end());
		int mi = sup+1, ma = sup+1;
		int psize = ps.size();
		int i = 0;
		while(i < psize) {
			int plus = 0, minus = 0;
			double f = ps[i].frac;
			while(i < psize && abs(ps[i].frac - f) < 1e-6)
				if(ps[i++].add) plus ++;
				else minus ++;
			mi = min(mi, sup-minus+1);
			ma = max(ma, sup+plus+1);
			sup += plus - minus;
		}
		ma += eq;
		cout << mi << " " << ma << "\n";
	}

	return 0;
}