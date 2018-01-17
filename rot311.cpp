#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define fr(i, L) for(int i = 0; i < L; i++)
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef vector< vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 9;

map<ii, bool> pecas_usadas;
int visitados[56] = {};
int pecas_disponiveis = 28;

void incializar_pecas() {
	int i, j;
	for(i = 0; i <= 6; i++)
		for(j = i; j <= 6; j++)
			pecas_usadas.insert(mp(mp(i, j), false));
}

bool testa_peca(int matriz[7][8], int i1, int j1, int i2, int j2) {
	if(pecas_disponiveis == 0)
		return true;

	int n1 = matriz[i1][j1], n2 = matriz[i2][j2];
	ii par = mp(min(n1, n2), max(n1, n2));

	if(pecas_usadas[par] == true)
		return false;

	pecas_usadas[par] = true;

	if(testa_peca(matriz, ))

	return false;
}

int main(void) {
	int n;
	int matriz[7][8];
	sc(n);

	while(n-- > 0) {
		incializar_pecas();

		fr(i, 7)
		fr(j, 8)
		sc(matriz[i][j]);
	}

	return 0;
}
