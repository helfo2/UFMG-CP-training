/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: The knapsack problem
*  Roteiro 4 - Problema 15
*  Estratégias: assim como o problema anterior, porem ainda mais direto, mais um problema que contradiz a solucao gulosa, exponial. 
*  Foi necessario o uso do raciocinio de DP. O problema de knapsack pode ser entendido como: dado um peso maximo para o qual a questao
*  pode ser resolvida e dois conjuntos, um de valores a serem trabalhados e outro com os respectivos pesos de cada valor, determinar 
*  qual a melhor solucao (aquela que maximiza o uso dos valores respeitando o peso maximo). No algoritmo de DP, o que se procura fazer 
*  e percorrer uma matriz resultado em termos dos valores e pesos e tratar 3 casos diferentes: um "caso base", em que o peso ou o valor 
*  seriam 0s, logo a primeira linha e a primeira coluna da matriz se constitui de zeros; o caso em que o peso atual se encaixa na solucao 
*  do problema, ou seja, e menor ou igual ao peso maximo (entao procura-se o maior valor entre a soma do valor atual e o valor na matriz correspondente
*  ao peso da iteracao menos o peso presente no indice do vetor de pesos e o valor correspondente ao peso atual na matriz resposta); e
*  o caso em que o peso ultrapassa o valor maximo, em que copia-se o valor correto. A resposta, entao, se encontra ao fim da matriz.
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

int knapsack(int c, vi& pesos, vi& valores) {
	int n = sz(pesos);
	int k[n + 1][c + 1];

	for(int i = 0; i <= n; i++) {
		for(int p = 0; p <= c; p++) {
			if(i == 0 || p == 0) { // base
				k[i][p] = 0; 
			}
			else if(pesos[i - 1] <= p) { // solucao
				k[i][p] = max(valores[i - 1] + k[i - 1][p - pesos[i - 1]],  k[i - 1][p]);
			}
			else { // fora da solucao
				k[i][p] = k[i - 1][p];
			}
		}
	}

	return k[n][c];
}

int main(void) {
	int s, n;
	vi size, value;


	sc2(s, n);

	value.resize(n);
	size.resize(n);

	for(int i = 0; i < n; i++) {
		sc(value[i]);
		sc(size[i]);	
	}

	printf("%d\n", knapsack(s, value, size));

	return 0;
}