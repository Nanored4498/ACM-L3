#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct Pos {
	double x, y;
	Pos(double x, double y): x(x), y(y) {}
};

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(3);

	int N;
	double Li, x, y;
	vector<double> Ls;
	vector<Pos> ps;
	vector<Pos> zones;
	while(cin >> N) {
		Ls.clear();
		ps.clear();
		zones.clear();
		double a = 9999, b = 0;
		for(int i = 0; i < N; i++) {
			cin >> Li;
			Ls.push_back(Li);
			double c = a - Li, d = b - Li;
			if(i == 0) a = Li;
			else if((c > 0) != (d > 0)) a = 0;
			else a = min(abs(c), abs(d));
			b = b + Li;
			zones.emplace_back(a, b);
		}
		cin >> x >> y;
		double dis = sqrt(x*x + y*y), d2;
		if(dis > b)	x *= b/dis, y *= b/dis, dis = b;
		else if(dis < a) x *= a/dis, y *= a/dis, dis = a;
		ps.emplace_back(x, y);
		for(int i = N-1; i >= 1; i--) {
			a = zones[i-1].x;
			b = zones[i-1].y;
			Li = Ls[i];

			double c = abs(dis - Li), d = dis + Li;
			if(a <= c && c <= b) d2 = (c + b) / 2.0;
			else if(a <= d && d <= b) d2 = (a + d) / 2.0;
			else d2 = (a + b) / 2.0;
			
			double d22 = d2*d2;
			double Li2 = Li*Li;
			double diff = (d22 + dis*dis - Li2) / (2.0 * y);
			double ratio = x / y;
			double pa = 1 + ratio*ratio;
			double pb = - diff * ratio;
			double pc = diff*diff - d22;
			double delta = pb*pb - pa*pc;
			double x2 = (-pb + sqrt(delta)) / pa;
			double y2 = sqrt(d22 - x2*x2);
			double dx = x-x2;
			double dy = y-y2;
			if(abs(Li2 - dx*dx-dy*dy) > 0.0001) y2 = -y2;
			dy = y-y2;

			x = x2;
			y = y2; 
			dis = d2;
			ps.emplace_back(x, y);
		}
		for(int i = N-1; i >= 0; i--) cout << ps[i].x << " " << ps[i].y << "\n";
	}

	return 0;
}