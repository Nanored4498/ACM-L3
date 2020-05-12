#include <iostream>
#include <vector>

using namespace std;

#define MAX_hw 2000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int hp, wp, hm, wm;
	string p[MAX_hw], mi;
	vector<int> KMP[MAX_hw], KMP2(MAX_hw+1), d(MAX_hw);
	for(int i = 0; i < MAX_hw; ++i) KMP[i].resize(MAX_hw+1);
	while(cin >> hp) {
		cin >> wp >> hm >> wm;
		int res = 0;
		KMP2[0] = -1;
		for(int i = 0; i < hp; ++i) {
			cin >> p[i];
			KMP[i][0] = -1;
			for(int j = 1; j <= wp; ++j) {
				KMP[i][j] = KMP[i][j-1];
				while(KMP[i][j] != -1 && p[i][KMP[i][j]] != p[i][j-1]) KMP[i][j] = KMP[i][KMP[i][j]];
				++ KMP[i][j];
			}
			KMP2[i+1] = KMP2[i];
			while(KMP2[i+1] != -1 && p[KMP2[i+1]] != p[i]) KMP2[i+1] = KMP2[KMP2[i+1]];
			++ KMP2[i+1];
		}
		for(int i = 0; i < wm; ++i) d[i] = 0;
		for(int i = 0; i < hm; ++i) {
			cin >> mi;
			int k=0, l=0;
			// while(k < wm) {
			// 	while(l != -1 && p[j][l] != mi[k]) l = KMP[j][l];
			// 	++k; ++l;
			// 	if(l == wp) {
			// 		if(j == 0 || last[j-1][k-l] == i-1) {
			// 			last[j][k-l] = i;
			// 			if(j == hp-1) ++res;
			// 			else if(to_find2.empty() || to_find2.back() != j+1) to_find2.push_back(j+1);
			// 		}
			// 		l = KMP[j][l];
			// 	}
			// }
		}
		cout << res << "\n";
	}

	return 0;
}