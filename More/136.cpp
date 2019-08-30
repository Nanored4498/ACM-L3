#include <iostream>
#include <queue>

using namespace std;

int main() {
	long long facts[3] = {2, 3, 5};
	priority_queue<pair<long long, int>> q;
	q.emplace(-1, 0);
	int n = 0;
	long long v;
	while((n++) < 1500) {
		auto a = q.top();
		q.pop();
		v = - a.first;
		for(int i = a.second; i < 3; i++) q.emplace(- v*facts[i], i);
	}
	cout << "The 1500'th ugly number is " << v << ".\n";
	return 0;
}