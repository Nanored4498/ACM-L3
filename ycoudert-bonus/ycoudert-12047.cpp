#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pa;
typedef vector<pa> ppv;

void f(int x, int *d, int p, ppv *v) {
    priority_queue<pa, ppv, greater<pa>> q;
	d[x] = 0;
    q.push({0, x});
    while(!q.empty()){
        int u = q.top().second;
		if(q.top().first > p) return;
        q.pop();
        for(pa &w : v[u]){
			int nd = d[u]+w.first;
            if(d[w.second] > nd){
                d[w.second] = nd;
                q.push({nd, w.second});
            }
        }
    }
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int T;
	int N, M, s, t, p;
	int i, a, b, c, res;
	ppv vs[10001], vt[10001];
	int ds[10001], dt[10001];
	cin >> T;

	while(T --> 0) {
		cin >> N >> M >> s >> t >> p;
		for(i = 1; i <= N; i++) {
			ds[i] = dt[i] = INF;
			vs[i].clear();
			vt[i].clear();
		}
		while(M --> 0) {
			cin >> a >> b >> c;
			vs[a].push_back({c, b});
			vt[b].push_back({c, a});
		}
		f(s, ds, p, vs);
		f(t, dt, p, vt);
		res = -1;
		for(i = 1; i <= N; i++) {
			int di = p - ds[i];
			if(di < 0) continue;
			for(pa u : vs[i])
				if(u.first > res && dt[u.second]+u.first <= di)
					res = u.first;
		}
		cout << res << "\n";
	}
	return 0;
}