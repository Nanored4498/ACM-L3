#include <iostream>
#include <vector>

using namespace std;

#define SIZE 30

vector<int> G[4*SIZE];
int ind, C;
int inds[4*SIZE], reach[4*SIZE];
bool in_stack[4*SIZE];
vector<int> stack;

void tarjan(int i) {
	inds[i] = ind;
	reach[i] = ind++;
	in_stack[i] = true;
	stack.push_back(i);
	for(int j : G[i]) {
		if(inds[j] == -1) {
			tarjan(j);
			reach[i] = min(reach[i], reach[j]);
		} else if(in_stack[j]) reach[i] = min(reach[i], reach[j]);
	}
	if(inds[i] == reach[i]) {
		int j;
		do {
			j = stack.back();
			stack.pop_back();
			in_stack[j] = false;
			inds[j] = C;
		} while(j != i);
		C ++;
	}
}

int main() {
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int S, A, m;
	int s1, a1, s2, a2;
	int ds, da;
	for(bool &b : in_stack) b = false;
	cin >> n;

	while(n --> 0) {
		cin >> S >> A >> m;

		for(auto &g : G) g.clear();
		for(int i = 0; i < m; i++) {
			cin >> s1 >> a1 >> s2 >> a2;
			s1 --, s2 --;
			a1 += SIZE-1, a2 += SIZE-1;
			s1 <<= 1, s2 <<= 1, a1 <<= 1, a2 <<= 1;
			if(s1 == s2) {
				if(a1 == a2) continue;
				ds = a2 > a1 ? 1 : 0;
				G[s1+1-ds].push_back(s1+ds);
			} else if(a1 == a2) {
				da = s2 > s1 ? 1 : 0;
				G[a1+1-da].push_back(a1+da);
			} else {
				ds = a2 > a1 ? 1 : 0;
				da = s2 > s1 ? 1 : 0;
				G[a1+1-da].push_back(a2+da);
				G[a1+1-da].push_back(s1+ds);
				G[a2+1-da].push_back(a1+da);
				G[a2+1-da].push_back(s2+ds);
				G[s1+1-ds].push_back(s2+ds);
				G[s1+1-ds].push_back(a1+da);
				G[s2+1-ds].push_back(s1+ds);
				G[s2+1-ds].push_back(a2+da);
			}
		}

		ind = 0, C = 0;
		for(int &i : inds) i = -1;
		for(int i = 0; i < 4*SIZE; i++)
			if(inds[i] == -1) tarjan(i);
		bool res = true;
		for(int i = 0; i < 2*SIZE; i++) {
			if(inds[2*i] == inds[2*i+1]) {
				res = false;
				break;
			}
		}
		if(res) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}