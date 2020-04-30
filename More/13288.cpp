#include <iostream>

using namespace std;

struct Point {
	int x, y;
};
inline int dist(const Point &a, const Point &b) { return abs(a.x - b.x) + abs(a.y - b.y); }
inline istream& operator>>(istream &stream, Point &a) {
	int x, y;
	cin >> x >> y;
	a = {x, y};
	return stream;
}

int N, M, M2;
Point bs[1000], cs[1000], r;
int lx[1000], ly[1999], w[1000][1999];
int xy[1000], yx[1999];
int Q[1999], rd, wr;
bool S[1000], T[1999];
int slack[1999], slackx[1999];

bool add(int j) {
	T[j] = true;
	int i = yx[j];
	if(i == -1) {	
		while(j >= 0) {
			int j2 = xy[slackx[j]];
			xy[slackx[j]] = j;
			yx[j] = slackx[j];
			j = j2;
		}
		return true;
	}
	if(S[i]) return false;
	S[i] = true;
	for(int j2 = 0; j2 < M2; ++j2) if(!T[j2]) {
		int ns = w[i][j2] - lx[i] - ly[j2];
		if(ns < slack[j2]) { slack[j2] = ns; slackx[j2] = i; if(ns == 0) Q[wr++] = j2; }
	}
	return false;
}


void augment() {
	int i, j;
	for(i = 0; i < N; ++i) S[i] = false;
	for(j = 0; j < M2; ++j) T[j] = false;
	i = 0;
	while(true) if(xy[i] == -1) { S[i] = true; break; } else ++i;
	for(j = 0; j < M2; ++j) {
		slackx[j] = i;
		slack[j] = w[i][j] - lx[i] - ly[j];
	}
	rd = wr = 0;
	while(true) {
		for(j = 0; j < M2; ++j) if(!T[j] && slack[j] == 0) if(add(j)) return;
		while(rd < wr) if(add(Q[rd++])) return;
		int delta = 5000;
		for(j = 0; j < M2; ++j) if(!T[j]) delta = std::min(delta, slack[j]);
		for(i = 0; i < N; ++i) if(S[i]) lx[i] += delta;
		for(j = 0; j < M2; ++j) if(T[j]) ly[j] -= delta; else slack[j] -= delta;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	while(cin >> N >> M) {
		M2 = M+N-1;
		for(int i = 0; i < N; ++i) cin >> bs[i];
		for(int j = 0; j < M; ++j) cin >> cs[j];
		cin >> r;
		int res = 0;
		for(int i = 0; i < N; ++i) {
			xy[i] = -1;
			w[i][M] = lx[i] = dist(r, bs[i]);
			res += w[i][M];
			for(int j = 0; j < M; ++j) {
				w[i][j] = dist(cs[j], bs[i]);
				lx[i] = std::min(lx[i], w[i][j]);
			}
			for(int j = M+1; j < M2; ++j) w[i][j] = w[i][M];
		}
		for(int j = 0; j < M2; ++j) { yx[j] = -1; ly[j] = 0; }
		for(int i = 0; i < N; ++i) augment();
		for(int i = 0; i < N; ++i) res += w[i][xy[i]];
		cout << res << "\n";
	}

	return 0;
}