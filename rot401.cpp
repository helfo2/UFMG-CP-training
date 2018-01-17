/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Engarrafamento
*  Roteiro 6 - Problema 2
*  Estratégias: a cada novo caso de teste, foi necessária a criação de um grafo que correspondia
*  aos dados informados (a implementação de grafo escolhida foi a classe, que possui uma lista de 
*  adjacência de pares de inteiros, vértice/peso). Nota-se que os grafos possuem arestas unidirecionais. 
*  Assim, tendo como base o algoritmo de Djikstra, implementou-se uma fila de prioridades, que considera
*  um vector de pares de inteiros a partir do comparador greater. Essa fila auxiliar é inicializada com 
*  distâncias infinitas (INF) e preenchida com as respectivas menores distâncias do vértice atual ao informado
*  como ponto de partida, além de ser atualizada conforme são calculadas as distâncias relativas dos caminhos.
*/
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
#include <list>
using namespace std;
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define p push
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
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

using namespace std;

int main(void) {
	int n, m, x, y, flag = 0;

	sc2(n, m);

	sc(y);

	if(y - 0 > m) flag = 1; 
	else {
		while(n-- > 1) {
			sc(x);

			if(x - y > m) {
				flag = 1;
				break;
			}

			//printf("%d - %d\n", x, y);
			y = x;
		}

		if(n == 0) {
			if(42195 - y > m) flag = 1;
		}
	}

	flag ? printf("N") : printf("S");

	return 0;
}