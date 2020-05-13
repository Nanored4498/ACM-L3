#include <iostream>
#include <vector>

using namespace std;

#define MAX_hw 2000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	uint hp, wp, hm, wm;
	string s;
	vector<uint> pc[MAX_hw], mc[MAX_hw+1];
	for(uint j = 0; j < MAX_hw; ++j) {
		pc[j].resize(MAX_hw/31+1);
		mc[j+1].resize(MAX_hw);
	}
	mc[0].assign(MAX_hw, 0);
	int KMP[MAX_hw+1];
	while(cin >> hp) {
		cin >> wp >> hm >> wm;
		uint block = min(hp, 31u);
		uint hpb = (hp-1)/block;
		uint lshift = ((hpb+1)*block-hp) % block;
		for(uint j = 0; j < wp; ++j) for(uint i = 0; i <= hpb; ++i) pc[j][i] = 0;
		for(int i = hp-1; i >= 0; --i) {
			cin >> s;
			uint k = i / block;
			uint add = 1u << (block-1u - (i%block));
			for(uint j = 0; j < wp; ++j) if(s[j] == 'x') pc[j][k] += add;
		}
		KMP[0] = -1;
		for(uint j = 1; j <= wp; ++j) {
			KMP[j] = KMP[j-1];
			while(KMP[j] != -1) {
				bool equal = true;
				for(uint i = 0; i <= hpb; ++i) if(pc[KMP[j]][i] != pc[j-1][i]) { equal = false; break; }
				if(equal) break;
				KMP[j] = KMP[KMP[j]];
			}
			++ KMP[j];
		}
		uint res = 0;
		uint add = 1 << (block-1);
		for(uint i = 1; i < hp; ++i) {
			cin >> s;
			for(uint j = 0; j < wm; ++j) {
				mc[i][j] = mc[i-1][j] >> 1;
				if(s[j] == 'x') mc[i][j] += add;
			}
		}
		for(uint i = hp; i <= hm; ++i) {
			cin >> s;
			int k=0;
			for(uint j = 0; j < wm; ++j) {
				mc[i][j] = mc[i-1][j] >> 1;
				if(s[j] == 'x') mc[i][j] += add;
				while(k != -1) {
					bool equal = true;
					for(uint l = 0; l < hpb; ++l) if(mc[i-l*block][j] != pc[k][l]) { equal = false; break; }
					if(equal && (mc[i-hpb*block][j] >> lshift) == (pc[k][hpb] >> lshift)) break;
					k = KMP[k];
				}
				++ k;
				if(k == wp) { ++ res; k = KMP[k]; }
			}
		}
		cout << res << "\n";
	}

	return 0;
}