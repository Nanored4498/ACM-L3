#include <iostream>
#include <algorithm>

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

typedef struct { int a, b, l; } road;

road create_road(int a, int b, int l) {
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

	int m, n;
	int i, x, y, z;
	int t, len, nr;
	road rs[200000], r;
	UF *un;

	while(true) {
		cin >> m >> n;
		if(m == 0) return 0;
		t = 0;
		for(i = 0; i < n; i++) {
			cin >> x >> y >> z;
			t += z;
			rs[i] = create_road(x, y, z);
		}
		sort(rs, rs + n, comp);
		len = 0, nr = 0, i = 0;
		un = new UF(m);
		while(nr < m-1) {
			r = rs[i];
			if(!un->connected(r.a, r.b)) {
				len += r.l;
				un->merge(r.a, r.b);
				nr ++;
			}
			i++;
		}
		//delete un;
		cout << (t - len) << "\n";
	}
}