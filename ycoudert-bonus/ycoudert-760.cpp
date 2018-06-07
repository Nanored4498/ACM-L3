#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	
	string a, b;
	int i, j, k;
	int m, n;
	vector<int> res;
	set<string> res2;
	int d[602];
	bool bo = false;

	while(cin >> a >> b) {
		if(bo) cout << "\n";
		else bo = true;
		n = a.length();
		a.append("#");
		a.append(b);
		m = 0;
		res.clear();
		for(i = 0; i <= n-m; i ++) {
			d[i] = 0;
			for(j = i+1; j < a.length(); j ++) {
				k = d[j-1];
				while(a[j] != a[i+k] && k > 0) k = d[i+k-1];
				if(a[j] == a[i+k]) {
					k++;
					if(j > n && k >= m) {
						if(k > m) {
							res.clear();
							m = k;
						}
						if(res.empty() || res.back() != i) res.push_back(i);
					}
					d[j] = k;
				} else d[j] = 0;
			}
		}
		if(m == 0) {
			cout << "No common sequence.\n";
		} else {
			res2.clear();
			for(int i : res) res2.insert(a.substr(i, m));
			for(string s : res2) cout << s << "\n";
		}
	}
	return 0;
}