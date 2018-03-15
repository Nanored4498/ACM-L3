#include <iostream>

using namespace std;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int V;
	int nv[301];
	int i, a, b;
	bool no;

	while(true) {
		cin >> V;
		if(V == 0) return 0;
		no = false;
		while(true) {
			cin >> a >> b;
			if(a == 0) break;
			if(nv[a] > 0 && nv[b] > 0) {no = true; cout << a << b << " ?\n";}
			nv[a] ++;
			nv[b] ++;
		}
		cout << no << " !\n";
		for(i = 1; i <= V; i++) {
			if(nv[i] == 2 || nv[i] > 3) no = true;
			nv[i] = 0;
		}
		if(no) cout << "NO\n";
		else cout << "YES\n";
	}
}