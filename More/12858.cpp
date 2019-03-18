#include <iostream>
#include <set>

using namespace std;

#define VI vector<int>
#define MV 10000

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int I, S, A, B;
	set<int> tempS;
	set<int> res, C[MV];

	while(cin >> I) {
		cin >> S;
		res.clear();
		for(int i = 0; i < I; i++) {
			cin >> A;
			C[i].clear();
			C[i].insert(A);
			res.insert(A);
		}
		for(int i = 0; i < S; i++) {
			cin >> A >> B;
			A--, B--;
			tempS.clear();
			for(int a : C[A])
				for(int b : C[B])
					tempS.insert(gcd(a, b));
			for(int c : tempS) {
				C[A].insert(c);
				C[B].insert(c);
				res.insert(c);
			}
		}
		cout << res.size() << "\n";
	}
	return 0;
}