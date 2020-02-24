#include <iostream>
#include <queue>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string s;
	int id, p;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int per[3001];
	while(true) {
		cin >> s;
		if(s.size() == 1) break;
		cin >> id >> p;
		q.push({p, id});
		per[id] = p;
	}
	int K;
	cin >> K;
	while(K --> 0) {
		int t = q.top().first; 
		int i = q.top().second;
		q.pop();
		cout << i << "\n";
		q.push({t+per[i], i});
	}

	return 0;
}