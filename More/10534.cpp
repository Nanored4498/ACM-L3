#include <iostream>

using namespace std;

#define MAX 10000

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, L, res;
	int v[MAX], l[MAX], m[MAX];
	while(cin >> N) {
		for(int i = 0; i < N; i++) cin >> v[i];
		L = 0;
		m[0] = -1;
		for(int i = 0; i < N; i++) {
			int x = v[i];
			int a = 0, b = L;
			while(b > a) {
				int c = (a+b+1)/2;
				if(m[c] < x) a = c;
				else b = c-1;
			}
			if(a == L) {
				m[a+1] = x;
				L ++;
			} else m[a+1] = min(m[a+1], x);
			l[i] = L;
		}
		res = 0;
		L = 0;
		m[0] = (int) 1e9;
		for(int i = N-1; i >= 0; i--) {
			int x = v[i];
			int a = 0, b = L;
			while(b > a) {
				int c = (a+b+1)/2;
				if(m[c] < x) a = c;
				else b = c-1;
			}
			if(a == L) {
				m[a+1] = x;
				L ++;
			} else m[a+1] = min(m[a+1], x);
			res = max(res, 2*min(L, l[i])-1);
		}
		cout << res << "\n";
	}

	return 0;
}