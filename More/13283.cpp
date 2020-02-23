#include <iostream>
#include <vector>

using namespace std;

#define MAX 2000

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	bool map[MAX][MAX+1];
	vector<int> count[MAX+1];
	for(int i = 0; i <= MAX; i++)
		count[i] = vector<int>(MAX+1);
	int height[MAX+1];

	int X, Y, N, D;
	int x, y, x2, y2;
	while(cin >> X >> Y >> N >> D) {
		// INIT MAP
		for(int i = 0; i < X; i++) {
			for(int j = 0; j < Y; j++)
				map[i][j] = false,
				count[i+1][j+1] = 0;
			map[i][Y] = true;
		}

		// ADD ORNAMENTS
		for(int i = 0; i < N; i++) {
			cin >> x >> x2 >> y >> y2;
			for(int a = x; a < x2; a++)
				for(int b = y; b < y2; b++)
					map[a][b] = true;
		}
		
		// MAX RECTANGLE
		for(int j = 0; j < Y; j++) height[j] = 0;
		vector<pair<int, int>> stack = {{0,-1}};
		for(int i = 0; i < X; i++) {
			for(int j = 0; j <= Y; j++) {
				height[j] = map[i][j] ? 0 : height[j]+1;
				int h=stack.back().first, j2=j;
				while(h > height[j]) {
					j2 = stack.back().second;
					stack.pop_back();
					count[h][j-j2] ++;
					count[max((h = stack.back().first), height[j])][j-j2] --;				
				}
				if(h < height[j]) stack.push_back({height[j], j2});
			}
		}

		// AGGREGATE
		for(int x=0; x <= X; x++) {
			count[x][Y-1] += 2*count[x][Y];
			for(int y = Y-2; y > 0; y--)
				count[x][y] += 2*count[x][y+1] - count[x][y+2];
		}
		for(int y=0; y <= Y; y++)
			for(int x = X-1; x > 0; x--)
				count[x][y] += count[x+1][y];

		for(int i = 0; i < D; i++) {
			cin >> x >> y;
			cout << count[x][y] << "\n";
		}
	}

	return 0;
}