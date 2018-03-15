#include<iostream>

using namespace std;

typedef struct {
	int deg;
	double a[11];
} poly;

poly derivate(poly *p) {
	poly q;
	q.deg = p->deg - 1;
	for(int i = 1; i <= p->deg; i++)
		q.a[i-1] = i*p->a[i];
	return q;
}

void rem_zero(poly *p) {
	while(p->deg >= 0 && abs(p->a[p->deg]) < 2e-10) p->deg -= 1;
}

poly* pgcd(poly *p, poly *q) {
	if(q->deg == -1) return p;
	int i, j;
	while((i = p->deg) >= (j = q->deg)) {
		double r = p->a[i] / q->a[j];
		while(j >= 0) p->a[i--] -= r * q->a[j--];
		rem_zero(p);
	}
	pgcd(q, p);
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int n, t, i, a;
	cin >> t;
	poly *p = (poly*) malloc(sizeof(poly)), *q = (poly*) malloc(sizeof(poly));

	while(t > 0) {
		cin >> n;
		p->deg = n;
		for(i = n; i >= 0; i--) {
			cin >> a;
			p->a[i] = a;
		}
		rem_zero(p);
		*q = derivate(p);
		if(pgcd(p, q)->deg == 0) cout << "Yes!\n";
		else cout << "No!\n";
		t --;
	}
	return 0;
}