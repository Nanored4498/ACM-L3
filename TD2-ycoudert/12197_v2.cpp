#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
    cout.tie(NULL);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(7);

	vector<pair<double, double>> coords(50000);
	pair<double, double> c2[50000];
	int n, i, j, m;
	double x, y, d, y2, dx, di;

	while(cin >> n) {
		if(n == 0) break;
		for(i = 0; i < n; i++) {
			cin >> x >> y;
			coords[i] = make_pair(x, y*y);
		}
		if(n == 1) {
			cout << coords[0].first << " " << sqrt(coords[0].second) << endl;
			continue;
		}
		sort(begin(coords), begin(coords)+n);
		m = 0;
		y = -1;
		for(i = 0; i < n; i++) {
			if(coords[i].second > y) {
				y = coords[i].second;
				c2[m] = coords[i];
				m ++;
			}
		}
		x = c2[m-1].first;
		i = n-1;
		y = -1;
		j = 50000;
		while(coords[i].first > x) {
			if(coords[i].second > y) {
				y = coords[i].second;
				j --;
				c2[j] = coords[i];
			}
			i --;
		}
		for(; j < 50000; j++) {
			c2[m] = c2[j];
			m ++;
		}
		d = (coords[n-1].first - coords[0].first) / 2;
		x = (coords[n-1].first + coords[0].first) / 2;
		while(d > 0.00001) {
			y = -1;
			y2 = -1;
			d /= 2;
			i = 0;
			while(c2[i].first < x) {
				dx = c2[i].first - x;
				di = dx * dx + c2[i].second;
				if(di > y) y = di;
				i ++;
			}
			for(;i < m; i++) {
				dx = c2[i].first - x;
				di = dx * dx + c2[i].second;
				if(di > y2) y2 = di;
			}
			if(y2 == y) break;
			else if(y2 > y) {
				x += d;
				y = y2;
				y2 = -1;
			} else {
				x -= d;
				y2 = -1;
			}
		}
		cout << x << " " << sqrt(y) << endl;
	}

	return 0;
}