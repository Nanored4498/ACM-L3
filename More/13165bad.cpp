#include <iostream>
#include <vector>

using namespace std;

#define MAX 250

int T, N, M;
int ind;
char a, b;
bool l[MAX*MAX*2], r[MAX*MAX*2], d[MAX*MAX*2], u[MAX*MAX*2];
vector<int> G[MAX*MAX*2];
bool seen[MAX*MAX*2];
char t[MAX*2];

void connect(int i, int j) { G[i].push_back(j); G[j].push_back(i); }

int f(int i, int pred=-1) {
	int l2 = l[i], r2 = r[i], d2 = d[i], u2 = u[i];
	seen[i] = true;
	vector<int> sons;
	int res = 1;
	for(int j : G[i]) {
		if(j == pred) continue;
		if(!seen[j]) {
			int add = f(j, i);
			if(add == -1) { //cout << i << " " << j << " " << j / 6 << " " << j % 6 << endl; 
				return -1; }
			res += add;
		}
		l2 += l[j], r2 += r[j], d2 += d[j], u2 += u[j];
		sons.push_back(j);
	}
	if(l2 > l[i] && r2 > r[i] && d2 > d[i] && u2 > u[i]) return -1;
	//if(i == 14) cout << "tets " << l1 << " " << l2 << " " << r1 << " " << r2 << " " << d1 << " " << d2 << " " << u1 << " " << u2 << "\n";
	//if(i == 14) cout << "test\n";
	bool bad = false;
	for(int j : sons) {
		if((!l[j] || l2 != 1) && (!r[j] || r2 != 1) && (!d[j] || d2 != 1) && (!u[j] || u2 != 1)) {
			bad = true;
			break;
		}
	}
	if(bad) return -1;
	l[i] = l2 > 0, r[i] = r2 > 0, d[i] = d2 > 0, u[i] = u2 > 0;
	return res;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	while(T --> 0) {
		cin >> N >> M;
		int size = 2*N*M;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> a >> b;
				a -= '0', b -= '0';
				int j2 = 2*j;
				bool horizon = (i+j) % 2 == 0;
				if(a == 0) {
					ind = 2*M*i + 2*j;
					l[ind] = (j == 0);
					r[ind] = (j == M-1) && !horizon;
					u[ind] = (i == 0);
					d[ind] = (i == N-1) && horizon;
					G[ind].clear();
					seen[ind] = false;
					if(horizon) {
						if(!l[ind]) {
							if(t[j2-1] == 0) connect(ind, ind-1);
							if(t[j2-2] == 0) connect(ind, ind-2);
						}
						if(!u[ind] && t[j2+1] == 0) connect(ind, ind-2*M+1);
					} else {
						if(!u[ind]) {
							if(t[j2] == 0) connect(ind, ind-2*M);
							if(t[j2+1] == 0) connect(ind, ind-2*M+1);
						}
						if(!l[ind] && t[j2-1] == 0) connect(ind, ind-1);
					}
				}
				if(b == 0) {
					ind = 2*M*i + 2*j + 1;
					l[ind] = (j == 0) && !horizon;
					r[ind] = (j == M-1);
					u[ind] = (i == 0) && horizon;
					d[ind] = (i == N-1);
					G[ind].clear();
					seen[ind] = false;
					if(horizon) {
						if(!u[ind] && t[j2+1] == 0) connect(ind, ind-2*M);
						if(a == 0) connect(ind, ind-1);
					} else {
						if(!l[ind] && t[j2-1] == 0) connect(ind, ind-2);
						if(a == 0) connect(ind, ind-1);
					}
				}
				t[j2] = a;
				t[j2+1] = b;
			}
		}
		int res = -1;
		for(int i = 0; i < 2*M; i++) {
			if(i % 4 == 3 || seen[i]) continue;
			res = f(i);
			//if(i == 4) cout << "test " << res << endl;
			if(res == 1 || !l[i] || !r[i] || !d[i] || !u[i]) res = -1;
			else if(res != -1) break;
		}
		if(res == -1) cout << "NO MINIMAL CORRIDOR\n";
		else cout << res << "\n";
	}

	return 0;
}