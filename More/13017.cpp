#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	ll s[MAX_N];
	greater<ll> comp{};
	cin >> T;
	while(T --> 0) {
		cin >> N;
		for(int i = 0; i < N; ++i) cin >> s[i];
		make_heap(s, s+N, comp);
		ll res = 0;
		while(N >= 2) {
			ll a = s[0]; pop_heap(s, s+N, comp); --N;
			a += s[0]; pop_heap(s, s+N, comp);
			res += a;
			s[N-1] = a;
			push_heap(s, s+N, comp);
		}
		cout << res << "\n";
	}

	return 0;
}