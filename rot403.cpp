/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Moedas
*  Roteiro 4 - Problema 3
*  Estratégias: foi necessario o uso de programacao dinamica neste problema, pelo fato de os valores das moedas serem
*  variaveis de acordo com a entrada. Apesar de ser um problema famoso de DP, esta longe de ser facil. A estrategia chave
*  e implementar dois vetores, um para os valores das moedas e outro para a quantidade de cada moeda, contendo a resposta
*  procurada. Assim, imprime-se o a quantidade de moedas para chegar ao valor informado pelo problema em uma estrutra com
*  funcionamento de hash, por indice. Basicamente, inicializa-se o vetor de valores de moedas com seus respectivos valores
*  informados na entrada e o vetor de quantidade com a flag que simboliza um valor inalcancavel (valor informado + 1). Dai
*  para cada indice do vetor de valores de moedas presente entre o intervalo de maior valor e o valor de fato procurado,
*  atualiza-se a quantidade de moedas iterando sobre todas as possibilidades de valores, de forma que, caso a diferenca entre
*  entre o maior valor de moedas e um valor interessar (>= 0), atualiza-se a quantidade minima do indice desse valor de moeda
*  somando-se 1 a quantidade do indice da diferenca.
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

int v[101]; // valores
int qnt[50001]; // quantidade

int min_moedas(int n, int m) {
	int i, j, maior_v = v[0], min, real_min;

	for(i = 0; i < n; i++) // encontra o valor de moeda maior
		if(maior_v > v[i]) maior_v = v[i];

	qnt[0] = 0;

	// inicializa as quantidades de moedas com 
	// flag de impossibilidade (nunca a qnt de moedas ultrapassa o valor maximo)
	for(i = 1; i < maior_v; i++) qnt[i] = m + 1; 

	for(i = maior_v; i <= m; i++) {
		min = m + 1; // flag

		for(j = 0; j < n; j++) { // para cada moeda testa-se o valor
			if(i - v[j] >= 0) { // se maior valor de moedas subtraido de cada valor for positivo ou neutro
				// soma 1 a quantidade presente no indice "maior valor achado" menos o valor atual
				// sempre funciona porque sempre consideramos a quantidade da moeda de maior valor, no minimo
				real_min = 1 + qnt[i - v[j]]; 
				if(real_min < min) min = real_min; // se for menor do que a flag
			}
		}

		qnt[i] = min; // atualiza quantidade conforme resultado testado para cada valor de moeda
	}

	return qnt[m];
}

int main(void) {
	int m, n, res;

	while(1) {
		sc(m);

		if(m == 0) break;

		sc(n);

		for(int i = 0; i < n; i++) sc(v[i]); 

		res = min_moedas(n, m);
		if(res > m) printf("Impossivel\n");
		else printf("%d\n", res); 
	}

	return 0;
}