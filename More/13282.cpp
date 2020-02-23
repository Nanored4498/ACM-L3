#include <iostream>
#include <queue>

using namespace std;

int a[2000], b[2000];
struct CookTime {
	int i, j, t;
};
bool operator>(const CookTime &x, const CookTime &y) { return x.t > y.t; }

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	while(cin >> N) {
		cin >> M;
		for(int i = 0; i < N; i++) cin >> a[i];
		for(int i = 0; i < M; i++) cin >> b[i];
		priority_queue<CookTime, vector<CookTime>, greater<CookTime>> q;
		int res=0, maxC=0;
		int j0 = 0;
		for(int i = 0; i < N; i++) {
			while(j0 < M  && b[j0] <= a[i]) j0 ++;
			if(j0 >= M) break;
			q.push({i, j0, b[j0]-a[i]});
		}
		int dt = 0, count=0;
		while(!q.empty()) {
			CookTime c = q.top();
			q.pop();
			if(c.t > dt) {
				if(count > maxC) res = dt, maxC = count;
				dt = c.t, count = 0;
			}
			count ++;
			int next = c.j+1;
			if(next < M) q.push({c.i, next, b[next]-a[c.i]});
		}
		if(count > maxC) res = dt, maxC = count;
		cout << res << "\n";
	}

	return 0;
}