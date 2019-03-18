#include <iostream>
#include <algorithm>
#include <math.h>
#include<iomanip>

using namespace std;

#define MN 200000
#define PII pair<long long, long long>

bool turnLeft(PII a, PII b, PII c) {
	return (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first) >= 0;
}

double dist(PII v, PII a, PII b, long double no) {
	return (b.first - a.first)*(v.first / no) + (b.second - a.second)*(v.second / no);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(6);

	long long N, R;
	long long x, y;
	PII b[MN], ch[MN+1];

	while(cin >> N) {
		cin >> R;
		for(long long i = 0; i < N; i++) {
			cin >> x >> y;
			b[i] = {x, y};
		}
		sort(b, b + N);
		long long n = 0;
		for(long long i = 0; i < N; i++) {
			while(n >= 2 && turnLeft(ch[n-2], ch[n-1], b[i])) n--;
			ch[n++] = b[i];
		}
		for(long long i = N-2, m = n; i >= 0; i--) {
			while(n > m && turnLeft(ch[n-2], ch[n-1], b[i])) n--;
			ch[n++] = b[i];
		}
		if(n < 4) {
			cout << "0.000000\n";
			continue;
		}
		long double res = 2*R;
		long long j = 2;
		for(long long i = 0; i < n-1; i++) {
			PII v = {ch[i+1].second - ch[i].second, ch[i].first - ch[i+1].first};
			long double no = sqrt(v.first*v.first + v.second*v.second);
			long double d = dist(v, ch[i], ch[j], no), nd;
			while((nd = dist(v, ch[i], ch[(j+1) % n], no)) >= d) {
				j = (j+1) % n;
				d = nd;
			}
			res = min(res, d);
		}
		cout << res << "\n";
	}

	return 0;
}