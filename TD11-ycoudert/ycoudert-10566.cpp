#include <iostream>
#include <iomanip>
#include <math.h>

#define E 1e-6

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(3);

	double x, y, c;
	double a, b, w;

	while(cin >> x >> y >> c) {
		a = 0;
		b = x;
		w = x/2;
		y = y*y;
		x = x*x;
		while(b-a > 0.00005) {
			double o = sqrt(x - w*w);
			double p = sqrt(y - w*w);
			if(o*p / (o+p) > c) a = w;
			else b = w;
			w = (a+b) / 2;
		}
		cout << w << "\n";
	}
	return 0;
}