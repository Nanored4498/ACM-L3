#include<iostream>

using namespace std;


long long f(short mod[20], short m, short n, short D, short s) {
	if(m == D) {
		if(n == 0 && s % D == 0) return 1;
		else return 0;
	}
	long long res = f(mod, m+1, n, D, s);
	long long x = 1;
	short ns = s;
	short mk = min(n, mod[m]);
	for(short k = 0; k < mk; k++) {
		x *= (mod[m]-k);
		x /= (k+1);
		ns += m;
		res += f(mod, m+1, n-k-1, D, ns) * x;
	}
	return res;
}

short modu(long n, short m) {
	short res = n % m;
	if(res < 0) return res+m;
	else return res;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	short N, Q, D, M, set = 1;
	short i, j;
	long nums[200];
	short mod[20];
	long long res;

	while(true) {
		cin >> N >> Q;
		if(N == 0) return 0;
		for(i = 0; i < N; i++) cin >> nums[i];
		cout << "SET " << set << ":\n";
		for(i = 1; i <= Q; i++) {
			cin >> D >> M;
			for(j = 0; j < D; j++) mod[j] = 0;
			for(j = 0; j < N; j++) mod[modu(nums[j], D)] += 1;
			res = f(mod, 0, M, D, 0);
			cout << "QUERY " << i << ": " << res << endl;
		}
		set ++;
	}
}