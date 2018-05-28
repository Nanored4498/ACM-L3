#include <iostream>
#include <vector>

#define INF 200000000

using namespace std;

struct A {
	int s, w, p;
};

typedef pair<int, int> P;
typedef vector<A> V;
typedef vector<P> VP;

V v[98];
bool see[98];
int pred[98];
int M = 0, W;
int t = 0;

int fu(VP d) {
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
	return fu(r);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int a, b, c, d, e, f, i;
	int w, res, add;

	while(true) {
		for(i = 0; i <= t; i++) v[i].clear(), see[i] = false;
		see[0] = true;
		cin >> M >> W;
		if(M == 0) return 0;
		t = 2*M-3;
		for(i = 2; i < M; i++) {
			cin >> a >> w;
			c = 2*a - 3;
			d = c+1;
			v[c].push_back({d, w, (int) v[d].size()});
			v[d].push_back({c, 0, (int) v[c].size()-1});
		}
		while(W --> 0) {
			cin >> a >> b >> w;
			if(a == 1) c = d = 0;
			else if(a == M) c = d = t;
			else c = 2*a - 3, d = c + 1;
			if(b == 1) e = f = 0;
			else if(b == M) e = f = t;
			else e = 2*b - 3, f = e + 1;
			v[d].push_back({e, w, (int) v[e].size()});
			v[e].push_back({d, 0, (int) v[d].size()-1});
			v[f].push_back({c, w, (int) v[c].size()});
			v[c].push_back({f, 0, (int) v[f].size()-1});
		}
		res = 0;
		while((add = fu({{0, INF }})) > 0) {
			res += add;
			for(i = 1; i <= t; i++) see[i] = false;
			i = t;
			while(i != 0) {
				A e = v[i][pred[i]];
				v[i][pred[i]].w += add;
				v[e.s][e.p].w -= add;
				i = e.s;
			}
		}
		cout << res << "\n";
	}
}