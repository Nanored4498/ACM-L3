#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define VI vector<int>

struct Road {
	int a, b, l;
};

bool cmp(Road a, Road b) { return a.l < b.l; }

#define VR vector<Road>

struct uf{
	VI A, w;
	
	uf(int n): w(n,1) {
		for(int i = 0; i < n; i++) A.push_back(i);
	}

	int find(int x){ return A[x]==x ? x : A[x]=find(A[x]); }
	
	int unite(int a,int b){
		int fa=find(a), fb=find(b);
		if(w[fb]>w[fa]) swap(fb,fa);
		A[fb] = fa;
		w[fa] += w[fb];
	}

	bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int nt;
	cin >> nt;
	VI res[3000];

	for(int t = 1; t <= nt; t++) {
		int N, R;
		cin >> N >> R;
		VR rs;
		int a, b, l;
		for(int r = 0; r < R; r++) {
			cin >> a >> b >> l;
			rs.push_back({a-1, b-1, l});
		}
		sort(rs.begin(), rs.end(), cmp);

		int Q;
		cin >> Q;
		vector<Road> qs;
		for(int q = 0; q < Q; q++) {
			cin >> a >> b;
			qs.push_back({a-1, b-1, 0});
		}

		uf u(N);
		int j = 0, k = 0;
		while(k < Q) {
			a = rs[j].a;
			b = rs[j].b;
			l = rs[j].l;
			if(!u.same(a, b)) {
				for(int i = 0; i < Q; i++)
					if((u.same(a, qs[i].a) && u.same(b, qs[i].b)) || (u.same(a, qs[i].b) && u.same(b, qs[i].a)))
						qs[i].l = l, k++;
				u.unite(a, b);
			}
			j ++;
		}
		cout << "Case " << t << "\n";
		for(Road q : qs)
			cout << q.l << "\n";
		cout << "\n";
	}
	return 0;
}