#include <iostream>
#include <vector>
#include <set>

using namespace std;

char im[202][202];
int con[202][202];
vector<int> comp;
vector<bool> col;
vector<set<int>> neighboors;

int simplify(int h, int w) {
	int c = con[h][w];
	while(c != comp[c]) {
		c = comp[c];
		con[h][w] = c;
	}
	return c;
}

int main(){
	char cs[7] = "ADJKSW";
	int map[6] = {5, 0, 3, 2, 4, 1};
	int nums[6];
	int H, W;
	for(int i = 0; i < 202; i++) im[i][0] = im[0][i] = 0;

	int testCase = 1;
	while(true) {
		cin >> H >> W;
		if(H == 0 && W == 0) return 0;
		for(int i = 0; i < 4*W+2; i++) im[H+1][i] = 0;
		for(int i = 0; i < H+2; i++) im[i][4*W+1] = 0;
		char c;
		for(int h = 0; h < H; h++) {
			for(int w = 0; w < W; w++) {
				cin >> c;
				if(c >= '0' && c <= '9') c = c - '0';
				else c = 10 + c - 'a';
				for(int i = 3; i >= 0; i--) {
					im[h+1][4*w+i+1] = c & 1;
					c >>= 1;
				} 
			}
		}
		comp.clear();
		col.clear();
		neighboors.clear();
		for(int h = 0; h < H+2; h++) {
			for(int w = 0; w < 4*W+2; w++) {
				int co = comp.size();
				if(h > 0 && im[h-1][w] == im[h][w]) co = min(co, simplify(h-1, w));
				if(w > 0 && im[h][w-1] == im[h][w]) co = min(co, simplify(h, w-1));
				con[h][w] = co;
				if(co == comp.size())
					comp.push_back(co), col.push_back(im[h][w]), neighboors.emplace_back();
				if(h > 0 && im[h-1][w] == im[h][w]) comp[con[h-1][w]] = min(comp[con[h-1][w]], co);
				if(w > 0 && im[h][w-1] == im[h][w]) comp[con[h][w-1]] = min(comp[con[h][w-1]], co);
			}
		}
		for(int h = 0; h < H+2; h++) {
			for(int w = 0; w < 4*W+2; w++) {
				if(h > 0 && im[h-1][w] != im[h][w]) {
					int c0 = simplify(h, w), c1 = simplify(h-1, w);
					neighboors[c0].insert(c1);
					neighboors[c1].insert(c0);
				}
				if(w > 0 && im[h][w-1] != im[h][w]) {
					int c0 = simplify(h, w), c1 = simplify(h, w-1);
					neighboors[c0].insert(c1);
					neighboors[c1].insert(c0);
				}
			}
		}
		for(int i = 0; i < 6; i++) nums[i] = 0;
		for(int i = 0; i < comp.size(); i++)
			if(col[i] && comp[i] == i)
				nums[map[neighboors[i].size()-1]] += 1;
		cout << "Case " << (testCase++) << ": ";
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < nums[i]; j++)
				cout << cs[i];
		cout << "\n";
	}
}