#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

#define INF 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pa;
typedef vector<pa> ppv;

ppv v[500];
int d[500];

int f(int n, int k) {
    priority_queue<pa, ppv, greater<pa>> q;
	for(int i = 0; i < n; i++)
    	q.push({0, 100*i});
    while(!q.empty()){
        int u = q.top().second;
		if(u % 100 == k) return d[u];
        q.pop();
        for(pa &w : v[u]){
			int nd = d[u]+w.first;
            if(d[w.second] > nd){
                d[w.second] = nd;
                q.push({nd, w.second});
            }
        }
    }
	return -1;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, k;
	int i, j, a, l, m;
	int T[5];
	vector<int> o[100];
	string s;

	while(cin >> n >> k) {
		for(i = 0; i < n; i++) {
			a = 100*i;
			for(j = 0; j < 100; j++) d[a+j] = INF, v[a+j].clear();
			d[a] = 0;
			cin >> T[i];
		}
		cin.ignore();
		for(i = 0; i < 100; i++) o[i].clear();
        for(i = 0; i < n; i++) {
			getline(cin, s);
			stringstream ss(s);
			a = -1;
			while(ss >> j) {
				l = 100*i+j;
				if(a >= 0) {
					m = T[i] * (l-a);
					v[a].push_back({m, l});
					v[l].push_back({m, a});
				}
				for(int u : o[j]) {
					v[u].push_back({60, l});
					v[l].push_back({60, u});
				}
				o[j].push_back(l);
				a = l;
			}
		}
		l = f(n, k);
		if(l == -1) cout << "IMPOSSIBLE\n";
		else cout << l << "\n";
	}
	return 0;
}