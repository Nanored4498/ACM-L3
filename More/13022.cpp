#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull f(ull x) {
	int p = 0;
	while((1uLL << (p+1)) <= x) ++p;
	ull res = p;
	for(int q = 1; q <= p; ++q)
		for(int N = 1; N <= q; ++N)
			for(int M = 1; M <= q-N; ++M)
				if(q % (N+M) == 0 || (q-N)%(N+M) == 0)
					++ res;
	++ p;
	ull block = 0;
	for(int N = 1; N < p; ++N) {
		block = (block<<1)+1;
		for(int M = p-N; M > 0; --M)
			if(p % (N+M) == 0 || (p-N)%(N+M) == 0) {
				ull y = 0;
				for(int i = p-N; i >= 0; i -= N+M) y += block << i;
				if(y > x) return res;
				++ res;
			}
	}
	if((1uLL << p)-1 <= x) ++ res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ull X, Y;
	while(cin >> X >> Y) cout << f(Y) - (X == 0 ? 0 : f(X-1)) << "\n";

	return 0;
}