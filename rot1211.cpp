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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
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

// int main(void) { _
// 	string entrada;
// 	char base = 'a';
// 	set<int> dif;

// 	while(1) { 
// 		cin >> entrada;

// 		if(entrada[0] == '*') break;
		
// 		int n = sz(entrada);

// 		//printf("n = %d\n", n);
		
// 		int qnt = 0, temp;
// 		fr(i, n) {
// 			temp = entrada[i] - base;
// 			//printf("temp = %d\n", temp);
// 			if(temp != 0) {
// 				if(dif.insert(temp).second == true) {
// 					qnt++;
// 				}
// 			}
// 		}

// 		set<int>::iterator it;
// 		/*tr(dif, it) {
// 			printf("set: %d\n", *it);
// 		}*/
		
// 		pri(qnt);
// 		dif.clear();
// 	}

// 	return 0;
// }

struct quantidade {
	int dist, valor;
};

typedef struct quantidade qnt;

int main(void) { _
	string entrada;
	char base = 'a';
	vector<qnt> q;

	while(1) { 
		cin >> entrada;
		printf("entrada = %s\n", entrada.c_str());
		if(entrada[0] == '*') break;
		
		int n = sz(entrada);
		q.resize(n + 1);

		for(int i = 1; i <= n; i++) {
			q[i].dist = entrada[i - 1] - base;
			q[i].valor = 0;	
		}
		
		q[0].dist = 0;
		q[0].valor = 1;

		for(int i = 0; i < n; i++) {
			printf("entrada[%d] = %c\n", i, entrada[i]);
			printf("q[%d].dist = %d\n", i, q[i].dist);
			printf("q[%d].valor = %d\n\n", i, q[i].valor);

			for(int j = i + 1; j <= n; j++) {
				

				if(q[j].dist != q[i].dist && q[j].valor <= q[i].valor) {
					q[j].valor++;
				} 
			}
		}
		
		printf("q[n].valor = %d\n", q[n].valor);
		//pri(q[n].valor);
		entrada.clear();
	}

	return 0;
}
