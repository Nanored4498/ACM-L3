#include<iostream>

#define SIZE 200000

using namespace std;

long t[SIZE];
int ti[SIZE];
long p2[19];

long somme(long i, long j) {
	if(i == 0) {
		long res = 0;
		while(j >= 0) {
			res += t[j];
			j = (j & (j+1)) - 1;
		}
		return res;
	} else return somme(0, j) - somme(0, i-1);
}

void inc(long i, short v, long N) {
	while(i < N) {
		t[i] += v;
		i = i | (i+1);
	}
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	short n = 1, k;
	long N, i, j;
	int v;
	char c;
	p2[0] = 1;
	for(k = 0; k < 18; k++) p2[k+1] = p2[k] << 1;
	for(k = 0; k < 19; k++) p2[k] = ~p2[k];

	while(true) {
		cin >> N;
		if(N == 0) break;
		if(n > 1) cout << "\n";
		cout << "Case " << n << ":\n";
		for(i = 0; i < N; i++) {
			cin >> t[i];
			ti[i] = t[i];
			k = 0;
			while((j = i & p2[k]) < i) {
				t[i] += t[j];
				k ++;
			}
		}
		while(true) {
			cin >> c;
			if(c == 'S') {
				cin >> i >> v;
				i--;
				inc(i, v-ti[i], N);
				ti[i] = v;
			} else if(c == 'M') {
				cin >> i >> j;
				cout << somme(i-1, j-1) << "\n";
			} else {
				cin.ignore(2);
				n++;
				break;
			}
		}
	}
	return 0;
}