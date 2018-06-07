#include <iostream>
#include <vector>
#include <utility>

#define MAX_nv 200001

using namespace std;

vector<pair<long, int>> r[100001]; //routes entre les villes
long res;

long f(long previous, long current) {
	long cr = 0, tem;
	for(int i = 0; i < r[current].size(); i++) {
		if(r[current][i].first == previous) continue;
		tem = f(current, r[current][i].first) + r[current][i].second;
		if(tem > 0) cr += tem;
	}
	res = max(res, cr);
	return cr;
}

int main() {
	cout.tie(nullptr);
    ios::sync_with_stdio(false);

	long n, i, a, b;
	int p;
	long ind[MAX_nv]; //nouveaux indices des villes
	long nv; //nombre de villes

	while(cin >> n) {
		if(n == 0) return 0;
		for(i = 0; i < MAX_nv; i++) ind[i] = -1;
		nv = 0;
		res = 0;
		for(i = 0; i < n; i++) {
			cin >> a >> b >> p;
			a--;
			b--;
			if(ind[a] == -1) ind[a] = nv++;
			if(ind[b] == -1) ind[b] = nv++;
			r[ind[a]].push_back(make_pair(ind[b], p));
			r[ind[b]].push_back(make_pair(ind[a], p));
		}
		f(0, 0);
		cout << res << endl;
		for(i = 0; i < nv; i++) r[i].clear();
	}

}