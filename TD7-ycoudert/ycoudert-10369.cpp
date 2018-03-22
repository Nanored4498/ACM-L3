#include <iostream>
#include <algorithm>
#include<iomanip>
#include <math.h>

using namespace std;

class UF {
	int *id, *sz;

	public:
	UF(int N) {
		id = new int[N];
		sz = new int[N];
    	for(int i = 0; i < N; i++) id[i] = i, sz[i] = 1;
	}

	~UF() { delete[] id; delete[] sz; }

	int find(int p) {
		int root = p;
		while (root != id[root]) root = id[root];
		while (p != root) {
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}

	void merge(int x, int y) {
		int i = find(x);
		int j = find(y);
		if (i == j) return;
		if (sz[i] < sz[j]) id[i] = j, sz[j] += sz[i];
		else id[j] = i, sz[i] += sz[j];
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

typedef struct { int a, b; long long l; } road;

road create_road(int a, int b, long long l) {
	road r;
	r.a = a, r.b = b, r.l = l;
	return r;
}

bool comp(road a, road b) {
	return a.l < b.l;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	int N, S, P;
	int i, j, nr, len;
	long long dx, dy, res;
	int c[500][2];
	road r[250000], ro;
	UF *un;
	cin >> N;

	while(N --> 0) {
		cin >> S >> P;
		for(i = 0; i < P; i++)
			cin >> c[i][0] >> c[i][1];
		nr = 0;
		for(i = 1; i < P; i++)
			for(j = 0; j < i; j++) {
				dx = c[i][0]-c[j][0];
				dy = c[i][1]-c[j][1];
				r[nr++] = create_road(i, j, dx*dx+dy*dy);
			}
		sort(r, r + nr, comp);
		nr = 0, i = 0;
		un = new UF(P);
		while(nr < P-S) {
			ro = r[i];
			if(!un->connected(ro.a, ro.b)) {
				res = ro.l;
				un->merge(ro.a, ro.b);
				nr ++;
			}
			i++;
		}
		cout << sqrt(res) << "\n";
	}
	return 0;
}