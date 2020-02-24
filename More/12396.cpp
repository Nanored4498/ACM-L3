#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000001
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	vector<long long> res(MAX);
	for(int i = 0; i < MAX; i++) res[i] = i;
	vector<bool> odd(MAX, false);
	vector<bool> prime(MAX, true);
	res[1] = 1;
	for(int i = 2; i < MAX; i++) {
		if(prime[i]) {
			res[i] = 1;
			bool add = odd[i] = true;
			for(int j=i<<1, k=2; j < MAX; j+=i, k++) {
				odd[j] = !odd[k];
				odd[k] = prime[j] = false;
				if(odd[j]) {
					if(add) res[j] *= i;
					else res[j] /= i;
					add = !add;
				}
			}
		}
		res[i] %= MOD;
		res[i] = (res[i-1] * res[i]) % MOD;
	}

	int n;
	while(true) {
		cin >> n;
		if(n == 0) break;
		cout << res[n] << "\n";
	}

	return 0;
}