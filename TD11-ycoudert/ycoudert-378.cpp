#include <iostream>
#include<iomanip>

#define E 1e-6

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	int N;
	double a, b, c, d, e, f, g, h;
	cin >> N;

	cout << "INTERSECTING LINES OUTPUT\n";
	while(N --> 0) {
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		double i = (d-b)*(g-e) + (a-c)*(h-f);
		if(abs(i) < E) {
			if(abs((f-b)*(c-a) - (e-a)*(d-b)) < E) cout << "LINE\n";
			else cout << "NONE\n";
			continue;
		}
		double j = ((f-b)*(g-e) + (a-e)*(h-f)) / i;
		cout << "POINT " << (a + j*(c-a)) << " " << (b + j*(d-b)) << "\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}