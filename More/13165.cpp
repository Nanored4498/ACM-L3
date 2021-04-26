#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
#define MAX 250

int N, M;
bool seen[MAX][2*MAX];
pii vs[MAX][2*MAX][5];
int C;
pii cor[2*MAX*MAX];
bool search;

char dfs(int i, int j) {
	seen[i][j] = true;
	if(search) cor[C++] = {i,j};
	char ans = 0;
	for(const pii &v : vs[i][j]) {
		bool out = false;
		if(v.first < 0) { ans |= 1; out = true; }
		if(v.first >= N) { ans |= 2; out = true; }
		if(v.second < 0) { ans |= 4; out = true; }
		if(v.second >= 2*M) { ans |= 8; out = true; }
		if(out) continue;
		if(!seen[v.first][v.second]) ans |= dfs(v.first, v.second);
	}
	return ans;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int i = 0; i < MAX; ++i)
		for(int j = 0; j < 2*MAX; ++j) {
			int t = (2*i+j) % 4;
			if(t == 0) { vs[i][j][0]={i,j+1}; vs[i][j][1]={i-1,j+1}; vs[i][j][2]={i,j-2}; vs[i][j][3]={i,j-1}; vs[i][j][4]={i+1,j}; }
			else if(t == 1) { vs[i][j][0]={i,j+1}; vs[i][j][1]={i-1,j}; vs[i][j][2]={i,j-1}; vs[i][j][3]={i+1,j-1}; vs[i][j][4]={i,j+2}; }
			else if(t == 2) { vs[i][j][0]={i-1,j+1}; vs[i][j][1]={i-1,j}; vs[i][j][2]={i,j-1}; vs[i][j][3]={i,j+1}; vs[i][j][4]={i,j+2}; }
			else { vs[i][j][0]={i,j+1}; vs[i][j][1]={i,j-1}; vs[i][j][2]={i,j-2}; vs[i][j][3]={i+1,j-1}; vs[i][j][4]={i+1,j}; }
		}

	int T;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < 2*M; ++j) {
				char c;
				cin >> c;
				seen[i][j] = c=='1';
			}
		search = true;
		for(int j = 0; j < 2*M; ++j) if(!seen[0][j] && dfs(C=0, j) == 15) {
			search = false;
			break;
		}
		if(search) cout << "NO MINIMAL CORRIDOR\n";
		else {
			bool ok = true;
			pii test[30];
			int nt = 0;
			for(int j = 0; j < C; ++j) seen[cor[j].first][cor[j].second] = false;
			for(int i = 0; i < C; ++i) {
				pii vis[5];
				int deg = 0;
				for(const pii &v : vs[cor[i].first][cor[i].second])
					if(v.first >= 0 && v.first < N && v.second >= 0 && v.second < 2*M && !seen[v.first][v.second])
						vis[deg++] = v;
				if(deg != 2) {
					if(nt+deg+1 >= 30) {
						ok = false;
						break;
					}
					test[nt++] = cor[i];
					if(deg > 1) while(deg--) test[nt++] = vis[deg];
				}
			}
			while(nt--) {
				if(!ok) break;
				seen[test[nt].first][test[nt].second] = true;
				for(const pii &v : vs[test[nt].first][test[nt].second])
					if(v.first >= 0 && v.first < N && v.second >= 0 && v.second < 2*M && !seen[v.first][v.second] && dfs(v.first, v.second) == 15) {
						ok = false;
						break;
					}
				for(int j = 0; j < C; ++j) seen[cor[j].first][cor[j].second] = false;
			}
			if(ok) cout << C << "\n";
			else cout << "NO MINIMAL CORRIDOR\n";
		}
	}

	return 0;
}