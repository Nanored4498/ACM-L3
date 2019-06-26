#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define MOD 1000003

set<char> leet = {'o', 'i', 'e', 's', 't'};
long long count[21][1001][8];
long long res;
int A, B, N;
string W;
int n_node;

struct Node {
	int num;
	map<char, Node*> next, next2;
	Node* suff;
	bool bad = false;
	int nlu=26, nd=10;

	Node(): num(n_node++) {}

	Node* add_child(char c) {
		if(next.count(c)) return next[c];
		else {
			next[c] = next2[c] = new Node();
			nlu --;
			if(leet.count(c)) nd--;
			return next[c];
		}
	}

	void set_suff(Node* s) {
		suff = s;
		if(s->bad) {
			bad = true;
			next.clear();
			next2.clear();
			return;
		}
		for(auto a : s->next2) {
			if(next2.count(a.first)) continue;
			next2[a.first] = a.second;
			nlu --;
			if(leet.count(a.first)) nd--;
		}
	}
};

Node* find_suffix(Node* n, char c) {
	if(n->next.count(c)) return n->next[c];
	if(n->suff != n) return find_suffix(n->suff, c); 
	return n;
}

void compute_suffix(const vector<Node*> &nodes) {
	if(nodes.empty()) return;
	vector<Node*> next;
	for(Node* no : nodes) {
		for(auto a : no->next) {
			next.push_back(a.second);
			a.second->set_suff(find_suffix(no->suff, a.first));
		}
	}
	compute_suffix(next);
}

void compute_suffix0(Node* root) {
	root->suff = root;
	vector<Node*> next;
	for(auto a : root->next) {
		a.second->set_suff(root);
		next.push_back(a.second);
	}
	compute_suffix(next);
}

void f(int s, Node* n) {
	if(n->bad) return;
	if(s >= A) res = (res + count[s][n->num][7]) % MOD;
	for(int lud = 0; lud < 8; lud++) {
		int c = count[s][n->num][lud];
		if(c == 0) continue;
		count[s+1][0][lud|1] = (count[s+1][0][lud|1] + n->nlu * c) % MOD;
		count[s+1][0][lud|2] = (count[s+1][0][lud|2] + n->nlu * c) % MOD;
		count[s+1][0][lud|4] = (count[s+1][0][lud|4] + n->nd  * c) % MOD;
		for(auto a : n->next2) {
			int n2 = a.second->num;
			count[s+1][n2][lud|1] = (count[s+1][n2][lud|1] + c) % MOD;
			count[s+1][n2][lud|2] = (count[s+1][n2][lud|2] + c) % MOD;
			if(leet.count(a.first))
				count[s+1][n2][lud|4] = (count[s+1][n2][lud|4] + c) % MOD;
		}
	}
	for(auto a : n->next) f(s, a.second);
}

void ff(Node* n) {
	if(n->bad) return;
	res = (res + count[B][n->num][7]) % MOD;
	for(auto a : n->next) ff(a.second);
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int lud = 0; lud < 8; lud++)
		for(int n = 0; n < 1001; n++)
			count[0][n][lud] = 0;
	count[0][0][0] = 1;

	while(cin >> A) {
		cin >> B >> N;
		n_node = 0;
		Node *root = new Node();
		for(int i = 0; i < N; i++) {
			cin >> W;
			Node *node = root;
			for(char c : W) node = node->add_child(c);
			node->bad = true;
		}
		compute_suffix0(root);
		res = 0;
		for(int i = 0; i < B; i++) {
			for(int lud = 0; lud < 8; lud++)
				for(int n = 0; n < n_node; n++)
					count[i+1][n][lud] = 0;
			f(i, root);
		}
		ff(root);
		cout << res << "\n";
		delete root;
	}

	return 0;
}