#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rat { int x, i; };
bool compRat(Rat &a, Rat &b) { return a.x < b.x; }
#define VI vector<Rat>

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int N, d, n;
	int x, y, i;
	VI lines[1025];
	int starts[1025];
	int ends[1025];
	int sums[1025];
	int lens[1025];
	cin >> N;
	while(N --> 0){
		cin >> d >> n;
		int D = 2*d+1;
		for(i = 0; i < 1025; i++) {
			starts[i] = ends[i] = sums[i] = 0;
			lines[i].clear();
		}
		while(n --> 0) {
			cin >> x >> y >> i;
			lines[y].push_back({x, i});
		}
		for(i = 0; i < 1025; i++) {
			sort(lines[i].begin(), lines[i].end(), compRat);
			lens[i] = lines[i].size();
		}
		int res = 0;
		int x0 = 0, y0 = 0;
		for(x = 0; x < 1025; x++) {
			int s = 0;
			for(y = 0; y < 1025; y++) {
				while(ends[y] < lens[y] && lines[y][ends[y]].x <= x)
					sums[y] += lines[y][ends[y] ++].i;
				while(starts[y] < lens[y] && lines[y][starts[y]].x <= x-D)
					sums[y] -= lines[y][starts[y] ++].i;
				s += sums[y];
				if(y-D >= 0) s -= sums[y-D];
				if(s > res) {
					res = s;
					x0 = x, y0 = y;
				}
			}
		}
		cout << max(0, x0-d) << " " << max(0, y0-d) << " " << res << "\n";
	}

	return 0;
}