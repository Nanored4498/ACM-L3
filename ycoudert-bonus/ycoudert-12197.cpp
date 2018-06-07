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
	double dis[50000];
	int n, i, j, m, deb, md;
	double x, y, d, y2, dx;

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
		md = 0;
		while(c2[md].first < x) md ++;
		deb = 0;
		while(d > 0.00001) {
			y = -1;
			y2 = -1;
			d /= 2;
			for(i = deb; i < md; i++) {
				dx = c2[i].first - x;
				dis[i] = dx * dx + c2[i].second;
				if(dis[i] > y) y = dis[i];
			}
			for(i = md; i < m; i++) {
				dx = c2[i].first - x;
				dis[i] = dx * dx + c2[i].second;
				if(dis[i] > y2) y2 = dis[i];
			}
			if(y2 == y) break;
			else if(y2 > y) {
				x += d;
				y = y2;
				y2 = -1;
				j = deb;
				for(i = deb; i < m; i++) {
					if(dis[i] > y2) {
						y2 = dis[i];
						c2[j] = c2[i];
						j ++;
						if(c2[i].first > x) {
							md = j-1;
							break;
						}
					}
				}
				if(i == m) md = j;
				for(i ++; i < m; i++) {
					if(dis[i] > y2) {
						y2 = dis[i];
						c2[j] = c2[i];
						j ++;
					}
				}
				m = j;
			} else {
				x -= d;
				y2 = -1;
				j = m-1;
				for(i = m-1; i >= deb; i--) {
					if(dis[i] > y2) {
						y2 = dis[i];
						c2[j] = c2[i];
						j --;
						if(c2[i].first <= x) {
							md = j+2;
							break;
						}
					}
				}
				if(i == deb-1) md = j+1;
				for(i --; i >= deb; i--) {
					if(dis[i] > y2) {
						y2 = dis[i];
						c2[j] = c2[i];
						j --;
					}
				}
				deb = j+1;
			}
		}
		cout << x << " " << sqrt(y) << endl;
	}

	return 0;
}