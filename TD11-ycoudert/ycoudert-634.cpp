#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int P[2], p[1000][2], n;
	int i, j, c;

	while(cin >> n) {
		if(n == 0) return 0;
		for(i = 0; i < n; i++) cin >> p[i][0] >> p[i][1];;
		cin >> P[0] >> P[1];
		c = 0;
		i = 0, j = n-1;
		while(i < n) {
			if(p[i][1] > P[1] != p[j][1] > P[1] && p[i][0] > P[0]) c++;
			j = i++;
		}
		if(c % 2 == 0) cout << "F\n";
		else cout << "T\n";
	}
}