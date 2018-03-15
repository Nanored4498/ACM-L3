#include <iostream>
#include <vector>
#include <algorithm>

#define MP 1000000
#define M 1000000000000

using namespace std;

long search(long long *t, long a, long b, long long v) {
	if(a >= b) return a;
	long m = (a+b)/2;
	if(t[m] == v) return m;
	if(t[m] > v) return search(t, a, m-1, v);
	return search(t, m+1, b, v);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	long long pri[78500], pri2[78500], ap[80100];
	long long np = 2, nap = 0, j, i;
	pri[0] = 2; pri[1] = 3;
	pri2[0] = 4; pri2[1] = 9;
	i = 4;
	while(i <= M) {
		ap[nap++] = i;
		i *= 2;
	}
	i = 9;
	while(i <= M) {
		ap[nap++] = i;
		i *= 3;
	}
	for(i = 5; i < MP; i += 2) {
		bool b = true;
		for(j = 1; pri2[j] <= i; j++) {
			if(i % pri[j] == 0) {
				b = false;
				break;
			}
		}
		if(b) {
			pri[np] = i;
			j = i*i;
			pri2[np++] = j;
			while(j <= M) {
				ap[nap++] = j;
				j *= i;
			}
		}
	}
	sort(ap, ap+nap);

	int N;
	long long a, b, ma, mb;
	cin >> N;
	while(N > 0) {
		cin >> a >> b;
		ma = search(ap, 0, nap-1, a);
		mb = search(ap, 0, nap-1, b);
		if(ap[ma] < a) ma ++;
		if(ap[mb] > b) mb --;
		cout << (mb-ma+1) << "\n";
		N --;
	}

	return 0;
}