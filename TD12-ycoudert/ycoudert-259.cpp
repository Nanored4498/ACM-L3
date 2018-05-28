#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct A {
	int s, w, p;
};

typedef pair<int, int> P;
typedef vector<A> V;
typedef vector<P> VP;
typedef vector<int> VI;

//  t : 0 A : 1 ... Z : 26, 0 : 27 ... 9 = 36
V v[38];
bool see[38];
int pred[38];

bool f(VI d) {
	VI r;
	for(int a : d) {
		for(A b : v[a]) {
			if(see[b.s] || b.w == 0) continue;
			pred[b.s] = b.p;
			if(b.s == 0) return true;	
			see[b.s] = true;		
			r.push_back(b.s);
		}
	}
	if(r.empty()) return false;
	return f(r);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	
	char c;
	int n, i, j, k, res;
	string l;
	VP s;
	bool b;

	while(true) {
		getline(cin, l);
		if(l.length() < 3) return 0;
		for(i = 0; i < 37; i++) v[i].clear(), see[i] = false;
		s.clear();
		for(i = 27; i < 37; i++) {
			v[0].push_back({i, 1, 0});
			v[i].push_back({0, 1, i-27});
		}
		do {
			istringstream iss(l);
			iss >> c >> n;
			i = c-64;
			s.push_back({i, n});
			j = 0;
			while(true) {
				iss >> c;
				if(c == ';') break;
				k = c-21;
				v[i].push_back({k, 1, (int) v[k].size()});
				v[k].push_back({i, 0, j++});
			}
			getline(cin, l);
		} while(l.length() > 3);
		b = false;
		for(P a : s) {
			while(a.second --> 0) {
				see[a.first] = true;
				if(f({a.first})) {
					for(i = 0; i < 37; i++) see[i] = false;
					i = 0;
					while(i != a.first) {
						A e = v[i][pred[i]];
						v[i][pred[i]].w ++;
						v[e.s][e.p].w --;
						i = e.s;
					}
				} else {
					b = true;
					break;
				}
			}
			if(b) break;
		}
		if(b) cout << "!\n";
		else {
			for(i = 27; i < 37; i++) {
				b = true;
				for(A e : v[i]) {
					if(e.w == 1 && e.s != 0)  {
						cout << (char) (e.s+64);
						b = false;
						break;
					}
				}
				if(b) cout << "_";
			}
			cout << "\n";
		}
	}
}