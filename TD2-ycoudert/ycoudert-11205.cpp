#include<iostream>

using namespace std;

int main() {
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	short np;
	short P, N;
	int leds[100];
	short i, j, k, c;
	bool seen[32768];
	short res;
	int n, m, ma;
	int p2[16];

	p2[0] = 1;
	for(i = 1; i < 16; i++)
		p2[i] = 2*p2[i-1];
	cin >> np;

	for(i = 0; i < np; i++) {
		cin >> P >> N;
		for(j = 0; j < N; j ++) {
			leds[j] = 0;
			for(k = 0; k < P; k++) {
				cin >> c;
				if(c == 1) leds[j] += p2[k];
			}
		}
		if(N == 1) {
			cout << 0 << endl;
			continue;
		} else if(N == 2) {
			cout << 1 << endl;
			continue;
		} else if(N <= 4) j = 2;
		else if(N <= 8) j = 3;
		else if(N <= 16) j = 4;
		else if(N <= 32) j = 5;
		else if(N <= 64) j = 6;
		else j = 7;

		n = p2[j]-1;
		res = P;
		ma = p2[P+1];

		while(n < ma) {
			c = 0;
			for(k = 0; k < P; k++) {
				if((n & p2[k]) != 0) c ++;
			}
			if(c < j || c >= res) {
				n ++;
				continue;
			}
			for(k = 0; k < N; k++) {
				m = n & leds[k];
				if(seen[m]) {
					k --;
					for(; k >= 0; k--)
						seen[n & leds[k]] = false;
					break;
				}
				seen[m] = true;
			}
			if(k == N) {
				res = c;
				for(k = 0; k < N; k++)
					seen[n & leds[k]] = false;
				if(res == j) break;
			}
			n ++;
		}
		cout << res << endl;
	}

	return 0;
}