/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Pedido de desculpas
*  Roteiro 4 - Problema 4
*  Estratégias: mais um problema que contradiz a solucao gulosa, exponial. Foi necessario o uso do raciocinio de DP. O problema
*  de knapsack pode ser entendido como: dado um peso maximo para o qual a questao pode ser resolvida e dois conjuntos, um de
*  valores a serem trabalhados e outro com os respectivos pesos de cada valor, determinar qual a melhor solucao (aquela que
*  maximiza o uso dos valores respeitando o peso maximo). No algoritmo de DP, o que se procura fazer e percorrer uma matriz resultado
*  em termos dos valores e pesos e tratar 3 casos diferentes: um "caso base", em que o peso ou o valor seriam 0s, logo a primeira
*  linha e a primeira coluna da matriz se constitui de zeros; o caso em que o peso atual se encaixa na solucao do problema, ou seja,
*  e menor ou igual ao peso maximo (entao procura-se o maior valor entre a soma do valor atual e o valor na matriz correspondente
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

float unb_knapsack(int peso_max, float min, vi& pesos, vector<float>& valores) {
	int n = sz(valores);
	vector<float> r(peso_max + 1, 0.0);
	vi qnt(n);

	for(int i = 0; i <= peso_max; i++) {
		for(int j = 0; j < n; j++) {
			if(pesos[j] <= i) {
				r[i] = max(r[i], r[i - pesos[j]] + pesos[j]);
				

				//printf("r[%d]: %f\n", i - pesos[j], r[i - pesos[j]]);
				//printf("valores[%d]: %f\n", j, valores[j]);
			}
		}
	}

	for(int j = 0; j < n; j++) {
		printf("qnt[%d]: %d\n", j, qnt[j]);
	}

	return r[peso_max - 1];
}

int main(void) {
	int n, b, teste = 1;
	float p, min = 1.0;
	vi precos;
	vector<float> probs;

	while(1) {
		sc2(n, b);

		if(n == 0) break;

		precos.resize(n);
		probs.resize(n);

		for(int i = 0; i < n; i++) {
			sc(precos[i]);
			scanf("%f", &p);
			
			if(p < min) min = p;

			probs[i] = p;
		}

		printf("Teste %d\n%.3f\n\n", teste++, unb_knapsack(b, min, precos, probs));
	}

	return 0;
}