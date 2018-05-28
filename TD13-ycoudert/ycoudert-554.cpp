#include <iostream>
#include <set>

using namespace std;

string w;
set<string> d;
int i, j, k;

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	while(true) {
		getline(cin, w);
		if(w == "#") break;
		for(i = 0; i < w.length(); i++) w[i] -= 64;
		d.insert(w);
	}
	getline(cin, w);
	int n = w.length();
	for(i = 0; i < n; i++) w[i] -= w[i] == ' ' ? ' ' : 64;
	w[n] = 0;
	int b = 0, ba = 0;
	for(int a = 0; a < 27; a++) {
		j = 0, k = 1;
		int s = 0;
		while(k <= n) {
			if(w[k] == 0) {
				if(d.find(w.substr(j, k-j)) != d.end()) s ++;
				j = ++k;;
			} else k++;
		}
		if(s > b) ba = a, b = s;
		for(i = 0; i < n; i++) w[i] = w[i] == 26 ? 0 : w[i] + 1;
	}
	for(i = 0; i < n; i++) w[i] = (w[i] + ba) % 27;
	for(i = 0; i < n; i++) w[i] += w[i] == 0 ? ' ' : 64;
	j = 0, k = 0;
	for(i = 0; i < n; i++) {
		if(w[i] == ' ') {
			if(k + i - j + 1 <= 60) {
				if(k > 0) cout << " ";
				k += i-j + (k == 0 ? 0 : 1);
			} else {
				cout << "\n";
				k = i-j;
			}
			cout << w.substr(j, i-j);
			j = i+1;
		}
	}
	cout << "\n";
	return 0;
}