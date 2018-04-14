#include <iostream>

using namespace std;

int t = 0;
int Z, I, M, L;
int a[10000];
int r;

void f(int n, int m) {
	a[n] = m++;
	n = (Z*n + I) % M;
	if(a[n] > 0) r = m-a[n];
	else f(n, m);
	a[n] = 0;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	while(cin >> Z >> I >> M >> L) {
		if(Z == 0 && I == 0 && M == 0 && L == 0) return 0;
		f(L, 1);
		a[L] = 0;
		cout << "Case " << ++t << ": " << r << "\n";
	}
}