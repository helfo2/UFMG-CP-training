/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Elementar, meu caro Watson!
*  Roteiro 12 - Problema 8?
*  Estratégias: ao enterdermos o problema como um grafo, bastou guardar em um par os numeros e seus respectivos indices.
*  Ordenamos, entao, o par e guardamos seus indices num vetor de visitados. Caso ainda nao tenha sido visitado e se encontre na posicao
*  errada, trocamos o valor com sua posicao enquanto adicionamos 1 ao contador de trocas. Assim, para cada valor, somamos
*  a quantidade minima de trocas feitas ao somarmos o valor desse contador a resposta.
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

int min_swaps(vi& final) {
	int n = sz(final);
	ii pos[n];

	for(int i = 0; i < n; i++) {
		pos[i].first = final[i];
		pos[i].second = i;
	}

	sort(pos, pos + n); // sort pair nao tem iterator

	// visualizacao como grafo
	vector<bool> visitados(n, false);
	int resp = 0;

	for(int i = 0; i < n; i++) {
		if(visitados[i] || pos[i].second == i) // ja visitados ou ja na posicao correta
			continue;

		int qnt = 0;
		int j = i;

		while(!visitados[j]) {
			visitados[j] = 1;

			j = pos[j].second; // prox indice
			qnt++;
		}

		resp += qnt - 1;
	}

	return resp;
}


int main(void) {
	int t, n;
	vi final;
	sc(t);

	while(t-- > 0) {
		sc(n);
		final.resize(n);

		for(int i = 0; i < n; i++) {
			sc(final[i]);
		}

		pri(min_swaps(final));
	}
	return 0;
}