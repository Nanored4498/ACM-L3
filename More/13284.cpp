#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000
#define LL long long
#define VLL vector<LL>
#define mat vector<vector<LL>>

mat mul(const mat &a, const mat &b) {
	int n = a.size();
	mat res(n, VLL(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
	return res;
}

mat pow(mat &a, long long n) {
	if(n == 1) return a;
	mat e = pow(a, n/2);
	mat res = mul(e, e);
	if(n % 2 == 1) return mul(res, a);
	else return res;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int N;
	LL M;
	while(cin >> N >> M) {
		int n = 1 << N;
		mat a(n, VLL(n));
		for(int i = 0; i < n; i++) {
			a[i][0] = 1;
			for(int j = 1; j < n; j++) {
				if((j&1) == 0) a[i][j] = a[i>>1][j>>1];
				else if((j&2) == 0) a[i][j] = (i&1)==0 ? a[i>>2][j>>2] : 0;
				else a[i][j] = a[i>>2][j>>2] + ((i&1)==0 ? a[i>>1][j>>1] : 0);
			}
		}
		mat b = pow(a, M);
		LL res = 0;
		for(int i = 0; i < n; i++) res += b[n-1][i];
		res %= MOD;
		cout << res << "\n";
	}

	return 0;
}