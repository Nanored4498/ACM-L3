#include<iostream>
#include<sstream>
#include<math.h>

using namespace std;

/**
 * Le principe est de faire une dichotomie pour trouver l'indice maximale tel que
 * la vitesse est inférieur à P
**/

int main(){
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	int D, P;
	string s;
	int S[10001];
	int i, j, v;
	float a, b, x, y; //coefficients en cas de régularité
	int f;
	bool bo = false;

	/* tableaux de puissances */
	float pa[15];
	float pb[15];
	int p2[15];
	p2[0] = 1;
	for(i = 0; i < 14; i++)
		p2[i+1]=2*p2[i];
	
	while(cin >> D >> P) {
		getline(cin, s);
		istringstream iss(s);
		i = 1;
		iss >> v;
		if(v > P) {
			cout << "The spider is going to fall!\n";
			continue;
		}
		S[0] = v;
		while(iss >> v) {
			if(v > P) {
				cout << (D-i+1) << endl;
				bo = true;
				break;
			}
			S[i] = v;
			i ++;
		}
		if(bo) {
			bo = false;
			continue;
		}
		if(i == D+1)  cout << "The spider may fall!\n";
		else {
			if(S[1] == 0) { //si la liste commence par deux zéros la liste ne contient que des zéros
				cout << "The spider may fall!\n";
				continue;
			}
			/**
			 * On cherche les coefficients permettant de calculer tous
			 * les termes de la suite
			 * u(n+2) = a*u(n+1) + b*u(n)
			 * x = racine du discriminant de "X^2 - aX - b = 0"
			 * puis u(n) = x*pa[0]^n + y*pb[0]^n
			**/
			b = (S[2]*S[2] - S[3]*S[1]) / (S[0]*S[2] - S[1]*S[1]);
			a = (S[2] - b*S[0]) / S[1];
			x = sqrt(a*a + 4*b);
			pb[0] = (a - x)/2;
			pa[0] = pb[0] + x;
			x = (S[0]*pb[0] - S[1]) / (pb[0] - pa[0]);
			y = S[0] - x;
			i = 0;
			f = round(x*pa[0] + y*pb[0]); //la valeur de la suite que l'on regarde actuellement
			/**
			 * On calcul les puissances nécessaires des coefficients
			 * tout en avançant dans la liste jusqu'à ce qu'on rencontre une valeur
			 * strictement plus grande que P ou qu'on aille plus loin que le waterfall
			**/
			while(p2[i] <= D && f <= P) {
				pa[i+1] = pa[i]*pa[i];
				pb[i+1] = pb[i]*pb[i];
				i ++;
				f = round(x*pa[i] + y*pb[i]);
			}
			j = p2[i];
			a = pa[i];
			b = pb[i];
			i--;
			/**
			 * Maintenant on effectue une sorte de dichotomie entre les deux dernières
			 * valeur de f trouvés. j stocke l'indice actuelle et a et b sont désormais
			 * les puissances utilisées pour calculer f.
			**/
			while(i > 0) {
				i--;
				if(j > D || f > P) {
					a /= pa[i];
					b /= pb[i];
					j -= p2[i];
				} else {
					a *= pa[i];
					b *= pb[i];
					j += p2[i];
				}
				f = round(x*a + y*b);
			}
			if(j > D || (j==D && f<=P)) cout << "The spider may fall!\n";
			else if(f > P) cout << (D-j+1) << endl;
			else cout << (D-j) << endl;
		}
	}
	return 0;
}
