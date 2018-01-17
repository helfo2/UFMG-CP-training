/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Desempilhando Caixas
*  Roteiro 12 - Problema 2
*  Estratégias: por meio de DP, procurou-se processar a entrada da seguinte maneira: sabendo que a caixa 1 é sempre a desejada,
*  assim que lemos a mesma guardamos em que pilha e a que altura ela se encontra. Enquanto isso, as quantidades de caixas de todas
*  pilhas são guardadas em um vetor. Enfim, a altura (quantas caixas devemos tirar) que satisfaz o problema é a quantidade de caixas
*  da pilha que contém a caixa 1 menos a altura onde ela se econtra. Como nao precisamos processar a tal pilha, somamos todas as 
*  quantidades de caixas que devemos retirar para podermos retirar a caixa 1 (pilhas ao lado). Assim que satisfizermos a questão da 
*  altura, basta saber de que forma minimizaremos o trabalho de Joãozinho.
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
	int n, p, qnt, c, resp, pilha1, altura1;
	vi pilhas;

	while(1) {
		sc2(n, p);

		if(n == 0) break;

		pilhas.resize(p);

		pilha1 = 0; altura1 = 0;
		for(int i = 0; i < p; i++) {
			sc(qnt);
			pilhas[i] = qnt;
			
			//printf("qnt = %d\n", qnt);

			for(int j = 0; j < pilhas[i]; j++) {
				sc(c);

				//printf("c = %d   i = %d\n", c, i);
				if(c == 1) {
					pilha1 = i; // pilha onde se encontra a caixa 1
					altura1 = j + 1; // altura onde se encontra a caixa 1 (quantas caixas há debaixo dela)
				}
			}
		}

		//printf("pilha1 = %d\n", pilha1);

		int altura = pilhas[pilha1] - altura1;
		int esq = altura, dir = altura;

		for(int i = pilha1 - 1; i >= 0; i--) { // quantas caixas deve-se retirar do lado esquerdo
			if(pilhas[i] >= altura1)
				esq += pilhas[i] - altura1 + 1;
			else break;
		}

		for(int i = pilha1 + 1; i < p; i++) { // quantas caixas deve-se retirar do lado direito
			if(pilhas[i] >= altura1)
				dir += pilhas[i] - altura1 + 1;
			else break;
		}

		//printf("esq = %d\n", esq);
		//printf("dir = %d\n", dir);
		

		//resp = min(esq, dir) + pilhas[pilha1] - altura1 - 1;
		resp = min(esq, dir);

		pri(resp);
	}

	return 0;
}