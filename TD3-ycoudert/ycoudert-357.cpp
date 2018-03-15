#include<iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n;
	long long m, n2, n3;
	int c0[10] = {1, 2, 4, 6, 9, 13, 18, 24, 31, 39};
	int c1[10] = {55, 81, 116, 154, 201, 257, 322, 396, 479, 571};

	while(cin >> n) {
		if(n < 5) {
			cout << "There is only 1 way to produce " << n << " cents change.\n";
			continue;
		}
		n2 = n/50;
		n3 = (n%50) / 5;
		m = (25*n2*n2*n2*n2+(95+10*n3)*n2*n2*n2+(119+(3*n3*n3+57*n3)/2)*n2*n2+c1[n3]*n2)/6 + c0[n3];
		cout << "There are " << m << " ways to produce " << n << " cents change.\n";
	}

	return 0;
}