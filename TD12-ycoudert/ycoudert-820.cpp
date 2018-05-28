#include <iostream>
#include <vector>

using namespace std;

struct A {
	int s, w, p;
};

typedef pair<int, int> P;
typedef vector<A> V;
typedef vector<P> VP;

V v[101];
bool see[101];
int pred[101];
int n = 0, s, t, c;

int f(VP d) {
	VP r;
	for(P a : d) {
		for(A b : v[a.first]) {
			if(see[b.s] || b.w <= 0) continue;
			pred[b.s] = b.p;
			if(b.s == t) return min(a.second, b.w);	
			see[b.s] = true;		
			r.push_back({b.s, min(a.second, b.w)});
		}
	}
	if(r.empty()) return 0;
	return f(r);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	
	int a, b, w;
	int i, res, add;
	int T = 0;

	while(true) {
		for(i = 1; i <= n; i++) v[i].clear();
		if(n > 0) cout << "\n";
		cin >> n;
		if(n == 0) return 0;
		cin >> s >> t >> c;
		while(c --> 0) {
			cin >> a >> b >> w;
			v[a].push_back({b, w, v[b].size()});
			v[b].push_back({a, w, v[a].size()-1});
		}
		res = 0;
		see[s] = true;
		while((add = f({{s, 2000}})) > 0) {
			res += add;
			for(i = 1; i <= n; i++) see[i] = false;
			see[s] = true;
			i = t;
			while(i != s) {
				A e = v[i][pred[i]];
				v[i][pred[i]].w += add;
				v[e.s][e.p].w -= add;
				i = e.s;
			}
		}
		for(i = 1; i <= n; i++) see[i] = false;
		cout << "Network " << ++T << "\n";
		cout << "The bandwidth is " << res << ".\n";
	}
}