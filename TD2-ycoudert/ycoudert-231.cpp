#include<iostream>

using namespace std;

int main() {
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	int n=1, v, i = 0, j;
	int res = 1, m;
	int val[33000], ma[33000];
	while(cin >> v) {
		if(v == -1) {
			cin >> v;
			if(v != -1) {
				cout << "Test #" << n << ":\n  maximum possible interceptions: " << res << "\n\n";
				n ++;
				res = 1;
				i = 0;
			} else cout << "Test #" << n << ":\n  maximum possible interceptions: " << res << endl;
		}
		val[i] = v;
		m = 0;
		for(j = 0; j < i; j++)
			if(val[j] >= v && ma[j] > m)
				m = ma[j];
		ma[i] = m+1;
		if(m+1 > res)
			res = m+1;
		i ++;
	}
	return 0;
}