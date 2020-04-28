#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> G[10000];

int num[10000], min_num[10000], s[10000], pred[10000];
bool in_s[10000];
int cnum, ss;

bool augment(int i) {
	for(int j : G[i]) if(pred[j] == -1 || (num[pred[j]] != num[i] && (num[pred[j]] = num[i], augment(pred[j])))) {
		pred[j] = i;
		return true;
	}
	return false;
}

bool tarjan(int i) {
	num[i] = min_num[i] = cnum++;
	s[ss++] = i;
	in_s[i] = true;
	int j, k = 0;
	while(k < G[i].size()) {
		j = G[i][k];
		if(num[j] == -1) {
			if(!tarjan(j)) return false;
			if(!in_s[j])	{
				G[i][k] = G[i].back();
				G[i].pop_back();
				continue;
			}
			min_num[i] = std::min(min_num[i], min_num[j]);
		} else if(in_s[j]) min_num[i] = std::min(min_num[i], num[j]);
		else {
			G[i][k] = G[i].back();
			G[i].pop_back();
			continue;
		}
		++ k;
	}
	if(min_num[i] == num[i]) do {
		j = s[--ss];
		if(!augment(j)) return false;
		in_s[j] = false;
	} while(j != i);
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	while(cin >> N >> M) {
		int a, b;
		if(M < N) {
			for(int i = 0; i < M; ++i) cin >> a >> b;
			std::cout << "NO\n";
			continue;
		}
		for(int i = 0; i < N; ++i) {
			G[i].clear();
			num[i] = min_num[i] = pred[i] = -1;
			in_s[i] = false;
		}
		for(int i = 0; i < M; ++i) {
			cin >> a >> b;
			G[a].push_back(b);
		}
		cnum = 0;
		ss = 0;
		string res = "YES\n";
		for(int i = 0; i < N; ++i) if(num[i] == -1 && !tarjan(i)) {
			res = "NO\n";
			break;
		}
		cout << res;
	}

	return 0;
}