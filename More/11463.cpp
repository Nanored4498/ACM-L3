#include <iostream>
#include <vector>

using namespace std;

void dijkstra(vector<int> s, int* dis, int d, vector<int>* G) {
	vector<int> next;
	d++;
	for(int i : s)
		for(int j : G[i])
			if(dis[j] == -1)
				dis[j] = d, next.push_back(j);
	if(!next.empty())
		dijkstra(next, dis, d, G);
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T, N, R;
	int u, v, s, d, i;
	int dis_s[100], dis_d[100];
	vector<int> G[100];

	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N >> R;
		for(i = 0; i < N; i++)
			dis_s[i] = dis_d[i] = -1, G[i].clear();
		while(R --> 0) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cin >> s >> d;
		dis_s[s] = 0;
		dijkstra({s}, dis_s, 0, G);
		dis_d[d] = 0;
		dijkstra({d}, dis_d, 0, G);
		int res = 0;
		for(i = 0; i < N; i++)
			res = max(res, dis_s[i] + dis_d[i]);
		cout << "Case " << t << ": " << res << "\n";
	}
	return 0;
}