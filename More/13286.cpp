#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MP 999999999999

struct Recipe { int base, price, prestige; };
using VVR = vector<vector<Recipe>>;
struct Dish { long long price, prestige; };
using VD = vector<Dish>;

void simpl(int d, const VVR &rs, VD &ds) {
	if(ds[d].price < MP) return;
	if(rs[d].empty()) ds[d] = {0, 0};
	else for(const Recipe r: rs[d]) {
		simpl(r.base, rs, ds);
		long long pri = r.price + ds[r.base].price;
		long long pre = r.prestige + ds[r.base].prestige;
		if(pri < ds[d].price) ds[d] = {pri, pre};
		else if (pri == ds[d].price) ds[d].prestige = max(ds[d].prestige, pre);
	}
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int B, N;
	while(cin >> B) {
		cin >> N;
		map<string, int> m;
		VVR Rs;
		VD Ds;
		string ddn, bdn, ai;
		int price, prestige;
		while(N --> 0) {
			cin >> ddn >> bdn >> ai >> price >> prestige;
			if(!m.count(ddn)) m[ddn] = m.size(), Rs.emplace_back(), Ds.push_back({MP, MP});
			if(!m.count(bdn)) m[bdn] = m.size(), Rs.emplace_back(), Ds.push_back({MP, MP});
			int idd = m[ddn], ibd = m[bdn];
			Rs[idd].push_back({ibd, price, prestige});
		}
		for(int i = 0; i < m.size(); i++) simpl(i, Rs, Ds);

		vector<long long> p(B+1, 0);
		for(const Dish &d : Ds) {
			if(d.prestige == 0) continue;
			for(int b = B; b >= d.price; b--)
				p[b] = max(p[b], d.prestige + p[b - d.price]);
		}
		int b = B;
		while(b > 0 && p[b-1]==p[b]) b--;
		cout << p[B] << "\n" << b << "\n";
	}

	return 0;
}