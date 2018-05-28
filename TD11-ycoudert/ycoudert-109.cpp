#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
	double x, y;
	bool operator <(P p) {
		return x < p.x || (x == p.x && y < p.y);
	}
};

typedef vector<P> VP;
typedef vector<VP> VVP;

bool left(P a, P b, P c) {
	return (c.y - a.y) * (b.x - a.x) >= (c.x - a.x) * (b.y - a.y);
}

int main() {
	cout.tie(nullptr);
    ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	int N;
	VVP ks;
	int i, j, s;
	P p;
	double res;
	bool in;

	while(cin >> N) {
		if(N == -1) break;
		VP k(N), k2(N);
		for(i = 0; i < N; i++) cin >> k[i].x >> k[i].y;
		sort(k.begin(), k.end());
		j = 0;
		for(i = 0; i < N; i++) {
			while(j > 1 && left(k[i], k2[j-1], k2[j-2])) j--;
			k2[j++] = k[i];
		}
		s = j;
		for(i = N-2; i >= 0; i--) {
			while(j > s && left(k[i], k2[j-1], k2[j-2])) j--;
			k2[j++] = k[i];
		}
		k2.resize(j);
		ks.push_back(k2);
	}
	while(cin >> p.x >> p.y) {
		for(VVP::iterator a = ks.begin(); a < ks.end(); a++) {
			s = (*a).size();
			i = 1;
			in = true;
			for(i = 1; i < s; i++) {
				if(left((*a)[i], (*a)[i-1], p)) {
					in = false;
					break;
				}
			}
			if(in) {
				for(i = 1; i < s; i++) res += (((*a)[i-1].x * (*a)[i].y) - ((*a)[i].x*(*a)[i-1].y)) / 2;
				ks.erase(a);
				break;
			}
		}
	}
	cout << res << "\n";
	return 0;
}