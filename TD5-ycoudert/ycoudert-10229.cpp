#include <iostream>

using namespace std;

pair<long, long> f(long n, long m) {
	if(n == 0) return make_pair(0, 1);
	if(n == 1) return make_pair(1, 1);
	if(n % 2 == 0) {
		long n2 = (n >> 1) - 1;
		pair<int, int> f2 = f(n2, m);
		long a = f2.first, b = f2.second;
		long c = a+b;
		return make_pair(((2*a+b)*b) % m, (c*c+b*b) % m);
	} else {
		long n2 = n >> 1;
		pair<int, int> f2 = f(n2, m);
		long a = f2.first, b = f2.second;
		return make_pair((a*a+b*b) % m, ((2*a+b)*b) % m);
	}
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	long n;
	int m;
	while(cin >> n >> m)
		cout << (m == 0 ? 0 : (f(n, 1 << m).first)) << "\n";
	return 0;
}