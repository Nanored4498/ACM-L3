#include <iostream>

using namespace std;

string s;
int n, i, j, k;

bool f() {
	for(j = i; j < n; j += i)
		for(k = 0; k < i; k++)
			if(s[k] != s[k+j]) return false;
	return true;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	while(true) {
		getline(cin, s);
		if(s == ".") return 0;
		n = s.length();
		for(i = 1; i <= n; i++) {
			if(n % i == 0 && f()) {
				cout << n/i << "\n";
				break;
			}
		}
	}
}