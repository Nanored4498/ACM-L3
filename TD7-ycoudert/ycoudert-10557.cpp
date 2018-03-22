#include <iostream>
#include <vector>

using namespace std;

int en[101], le[101];
bool seen[101], s2[101], s3[101];
vector<int> v[101];
int n, i, a, nv;

bool g(int a) {
	if(a == n) return true;
	s3[a] = true;
	for(int b : v[a]) if(!s3[b] && g(b)) return true;
	return false;
}

bool f(int a, int e) {
	if(a == n) return true;
	seen[a] = s2[a] = true;
	le[a] = e;
	for(int b : v[a]) {
		int ne = e + en[b];
		if(ne <= 0 || b > n) continue;
		if(s2[b]) {
			if(ne > le[b]) {
				for(i = 1; i <= n; i++) s3[i] = false;
				if(g(b)) return true;
			}
		} else if(!seen[b])
			if(f(b, ne)) return true;
	}
	s2[a] = false;
	return false;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	int c = 0;
	while(true) {
		cin >> n;
		c++;
		//if(c == 244) cout << n << "\n";
		if(n == -1) return 0;
		for(i = 1; i <= n; i++)
			v[i].clear(), seen[i] = s2[i] = false;
		for(i = 1; i <= n; i++) {
			cin >> en[i] >> nv;
			//if(c == 244) cout << en[i] << " " << nv << "\n";
			while(nv --> 0) {
				cin >> a;
				v[i].push_back(a);
			}
		}
		if(f(1, 100)) cout << "winnable\n";
		else cout << "hopeless\n";
	}
}