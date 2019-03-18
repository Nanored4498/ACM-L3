#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Build { int l, r, h, i; };
bool compHigh(Build &a, Build &b) { return (a.h > b.h || (a.h == b.h && a.i > b.i)); }
struct Pos { int x; bool deb; };
bool compPos(Pos &a, Pos &b) { return a.x < b.x; }

int main() {
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int c, n;
	int l, r, h;
	int i;
	cin >> c;
	vector<Build> bs;
	vector<vector<Pos>> lp;
	vector<int> ts;
	while(c --> 0) {
		cin >> n;
		bs.clear();
		lp.clear();
		ts.clear();
		for(i = 1; i <= n; i++) {
			cin >> l >> r >> h;
			bs.push_back({l, r, h, i});
		}
		sort(bs.begin(), bs.end(), compHigh);
		ts.push_back(bs[0].i);
		lp.push_back({{bs[0].l, true}, {bs[0].r, false}});
		int a, b, m;
		for(i = 1; i < n; i++) {
			a = 0, b = ts.size()-1;
			while(a < b) {
				m = (a+b) / 2;
				if(bs[i].i > ts[m]) b = m;
				else a = m+1;
			}
			if(bs[i].i > ts[a]) {
				ts[a] = bs[i].i;
				lp[a].push_back({bs[i].l, true});
				lp[a].push_back({bs[i].r, false});
			} else {
				ts.push_back(bs[i].i);
				lp.push_back({{bs[i].l, true}, {bs[i].r, false}});
			}
		}
		int op, last;
		int res = 0;
		for(auto &ps : lp) {
			sort(ps.begin(), ps.end(), compPos);
			op = 1;
			last = ps[0].x;
			for(i = 1; i < ps.size(); i++) {
				if(op > 0) res += ps[i].x - last;
				last = ps[i].x;
				if(ps[i].deb) op ++;
				else op --;
			}
		}
		cout << res << "\n";
	}

	return 0;
}