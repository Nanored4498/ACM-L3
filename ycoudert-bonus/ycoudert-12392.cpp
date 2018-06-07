#include<iostream>
#include <utility>

using namespace std;

int perm4[120][5] = {{0, 1, 2, 3, 4}, {0, 1, 2, 4, 3}, {0, 1, 3, 2, 4}, {0, 1, 3, 4, 2}, {0, 1, 4, 2, 3}, {0, 1, 4, 3, 2},
        {0, 2, 1, 3, 4}, {0, 2, 1, 4, 3}, {0, 2, 3, 1, 4}, {0, 2, 3, 4, 1}, {0, 2, 4, 1, 3}, {0, 2, 4, 3, 1}, {0, 3, 1, 2, 4},
        {0, 3, 1, 4, 2}, {0, 3, 2, 1, 4}, {0, 3, 2, 4, 1}, {0, 3, 4, 1, 2}, {0, 3, 4, 2, 1}, {0, 4, 1, 2, 3}, {0, 4, 1, 3, 2},
        {0, 4, 2, 1, 3}, {0, 4, 2, 3, 1}, {0, 4, 3, 1, 2}, {0, 4, 3, 2, 1}, {1, 0, 2, 3, 4}, {1, 0, 2, 4, 3}, {1, 0, 3, 2, 4},
        {1, 0, 3, 4, 2}, {1, 0, 4, 2, 3}, {1, 0, 4, 3, 2}, {1, 2, 0, 3, 4}, {1, 2, 0, 4, 3}, {1, 2, 3, 0, 4}, {1, 2, 3, 4, 0},
        {1, 2, 4, 0, 3}, {1, 2, 4, 3, 0}, {1, 3, 0, 2, 4}, {1, 3, 0, 4, 2}, {1, 3, 2, 0, 4}, {1, 3, 2, 4, 0}, {1, 3, 4, 0, 2},
        {1, 3, 4, 2, 0}, {1, 4, 0, 2, 3}, {1, 4, 0, 3, 2}, {1, 4, 2, 0, 3}, {1, 4, 2, 3, 0}, {1, 4, 3, 0, 2}, {1, 4, 3, 2, 0},
        {2, 0, 1, 3, 4}, {2, 0, 1, 4, 3}, {2, 0, 3, 1, 4}, {2, 0, 3, 4, 1}, {2, 0, 4, 1, 3}, {2, 0, 4, 3, 1}, {2, 1, 0, 3, 4},
        {2, 1, 0, 4, 3}, {2, 1, 3, 0, 4}, {2, 1, 3, 4, 0}, {2, 1, 4, 0, 3}, {2, 1, 4, 3, 0}, {2, 3, 0, 1, 4}, {2, 3, 0, 4, 1},
        {2, 3, 1, 0, 4}, {2, 3, 1, 4, 0}, {2, 3, 4, 0, 1}, {2, 3, 4, 1, 0}, {2, 4, 0, 1, 3}, {2, 4, 0, 3, 1}, {2, 4, 1, 0, 3},
        {2, 4, 1, 3, 0}, {2, 4, 3, 0, 1}, {2, 4, 3, 1, 0}, {3, 0, 1, 2, 4}, {3, 0, 1, 4, 2}, {3, 0, 2, 1, 4}, {3, 0, 2, 4, 1},
        {3, 0, 4, 1, 2}, {3, 0, 4, 2, 1}, {3, 1, 0, 2, 4}, {3, 1, 0, 4, 2}, {3, 1, 2, 0, 4}, {3, 1, 2, 4, 0}, {3, 1, 4, 0, 2},
        {3, 1, 4, 2, 0}, {3, 2, 0, 1, 4}, {3, 2, 0, 4, 1}, {3, 2, 1, 0, 4}, {3, 2, 1, 4, 0}, {3, 2, 4, 0, 1}, {3, 2, 4, 1, 0},
        {3, 4, 0, 1, 2}, {3, 4, 0, 2, 1}, {3, 4, 1, 0, 2}, {3, 4, 1, 2, 0}, {3, 4, 2, 0, 1}, {3, 4, 2, 1, 0}, {4, 0, 1, 2, 3},
        {4, 0, 1, 3, 2}, {4, 0, 2, 1, 3}, {4, 0, 2, 3, 1}, {4, 0, 3, 1, 2}, {4, 0, 3, 2, 1}, {4, 1, 0, 2, 3}, {4, 1, 0, 3, 2},
        {4, 1, 2, 0, 3}, {4, 1, 2, 3, 0}, {4, 1, 3, 0, 2}, {4, 1, 3, 2, 0}, {4, 2, 0, 1, 3}, {4, 2, 0, 3, 1}, {4, 2, 1, 0, 3},
        {4, 2, 1, 3, 0}, {4, 2, 3, 0, 1}, {4, 2, 3, 1, 0}, {4, 3, 0, 1, 2}, {4, 3, 0, 2, 1}, {4, 3, 1, 0, 2}, {4, 3, 1, 2, 0},
        {4, 3, 2, 0, 1}, {4, 3, 2, 1, 0}};
int perm3[24][4] = {{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}, {1, 0, 2, 3},
        {1, 0, 3, 2}, {1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0}, {2, 0, 1,3}, {2, 0, 3, 1}, {2, 1, 0, 3},
        {2, 1, 3, 0}, {2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1}, {3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0}};
int perm2[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int perm1[2][2] = {{0, 1}, {1, 0}};
int perm0[1][1] = {{0}};

struct tree {
    char v;
    tree *l, *r, *p;
};

tree* new_tree(char c, tree* p) {
    tree *res = (tree*) malloc(sizeof(tree));
    res->v = c;
    res->p = p;
    return res;
}

pair<int, short> evaluate(tree* t, int *v, int *p, short i) {
    int a;
    pair<int, short> pa;
    switch(t->v) {
        case '+':
            pa = evaluate(t->l, v, p, i);
            a = pa.first;
            pa = evaluate(t->r, v, p, pa.second);
            return make_pair(a + pa.first, pa.second);
        case '-':
            pa = evaluate(t->l, v, p, i);
            a = pa.first;
            pa = evaluate(t->r, v, p, pa.second);
            return make_pair(a - pa.first, pa.second);
        case '*':
            pa = evaluate(t->l, v, p, i);
            a = pa.first;
            pa = evaluate(t->r, v, p, pa.second);
            return make_pair(a * pa.first, pa.second);
        default:
            a = v[p[i]];
            return make_pair(a, i+1);
    }
}

int main() {
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    short n, i, j;
    int v[5], *p;
    tree *ta, *tb;
    char c;
    int m;
    bool bo;

    while(cin >> n) {
        if(n == 0) {
            cin >> m;
            break;
        }
        for(i = 0; i < n; i++)
            cin >> v[i];
        cin >> m;
        ta = new_tree(0, NULL);
        ta->p = ta;
        cin >> c;
        if(c == '(') {
            i = 1;
            while(i > 0) {
                cin >> c;
                switch(c) {
                    case '(':
                        i ++;
                        tb = new_tree(0, ta);
                        if(ta->l == NULL) ta->l = tb;
                        else ta->r = tb;
                        ta = tb;
                        break;
                    case ')':
                        ta = ta->p;
                        i --;
                        break;
                    case '+':
                    case '-':
                    case '*':
                        ta->v = c;
                        break;
                    default:
                        if(ta->l == NULL) ta->l = new_tree(c, ta);
                        else ta->r = new_tree(c, ta);
                        break;
                }
            }
        } else ta->v = c;
        bo = true;
        switch(n) {
            case 1:
                for(i = 0; i < 1; i++) {
                    if(evaluate(ta, v, perm0[i], 0).first == m) {
                        cout << "YES\n";
                        bo = false;
                        break;
                    }
                }
                break;
            case 2:
                for(i = 0; i < 2; i++) {
                    if(evaluate(ta, v, perm1[i], 0).first == m) {
                        cout << "YES\n";
                        bo = false;
                        break;
                    }
                }
                break;
            case 3:
                for(i = 0; i < 6; i++) {
                    if(evaluate(ta, v, perm2[i], 0).first == m) {
                        cout << "YES\n";
                        bo = false;
                        break;
                    }
                }
                break;
            case 4:
                for(i = 0; i < 24; i++) {
                    if(evaluate(ta, v, perm3[i], 0).first == m) {
                        cout << "YES\n";
                        bo = false;
                        break;
                    }
                }
                break;
            default:
                for(i = 0; i < 120; i++) {
                    if(evaluate(ta, v, perm4[i], 0).first == m) {
                        cout << "YES\n";
                        bo = false;
                        break;
                    }
                }
                break;
        }
        if(bo) cout << "NO\n";
    }

	return 0;
}