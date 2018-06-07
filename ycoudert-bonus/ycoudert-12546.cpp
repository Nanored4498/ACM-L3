#include<iostream>

#define M 1000000007

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int T, C, P, a;
	long long pk, asym, prod, sum;
	int k;

	cin >> T;
	for(int i = 1; i <= T; i++) {
		cin >> C;
		asym = 0;
		prod = 1;
		while(C > 0) {
			cin >> P >> a;
			sum = 0;
			pk = 1;
			for(k = 0; k < a; k++) {
				sum = (sum+pk) % M;
				pk = (pk*P) % M;
			}
			asym = ((sum + a*pk % M) * (asym + prod) + (asym*pk) % M) % M;
			prod = (prod*pk) % M;
			C --;
		}
		cout << "Case " << i << ": " << ((asym + 2*prod) % M) << "\n";
	}
	return 0;
}