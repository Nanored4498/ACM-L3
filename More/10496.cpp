#include <iostream>
#include <vector>

using namespace std;

struct Point { int x, y; };

inline int dist(const Point &p1, const Point &p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int f(const Point &start, vector<Point> &beepers, const Point &end) {
	int n = beepers.size();
	if(n == 0) return dist(start, end);
	else if(n == 1) return dist(start, beepers[0]) + dist(beepers[0], end);
	else {
		int res = 4400;
		for(int i = 0; i < n; i++) {
			Point s =  beepers[i];
			beepers[i] = beepers[n-1];
			beepers.pop_back();
			for(int j = 0; j < n-1; j++) {
				Point e = beepers[j];
				beepers[j] = beepers[n-2];
				beepers.pop_back();
				res = min(res, dist(start, s) + f(s, beepers, e) + dist(e, end));
				if(j == n-2) beepers.push_back(e);
				else {
					beepers.push_back(beepers[j]);
					beepers[j] = e;
				}
			}
			if(i == n-1) beepers.push_back(s);
			else {
				beepers.push_back(beepers[i]);
				beepers[i] = s;
			}
		}
		return res;
	}
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int x, y, n;
	while(T --> 0) {
		cin >> x >> y;	
		cin >> x >> y;
		Point start = {x, y};
		cin >> n;
		vector<Point> beepers;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			beepers.push_back({x, y});
		}
		cout << "The shortest path has length " << f(start, beepers, start) << "\n";
	}

	return 0;
}