/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Maçãs URI 1517
*  Roteiro 12 - Problema 3
*  Estratégias: Depois de ler as posicoes das macas num vetor de struct correspondente,
*  o raciocinio de DP foi da seguinte forma: no indice zero do vetor guardamos a posicao inicial
*  de Rafael e o tempo zero. Percorremos, a partir do fim, considerando que, se a soma das diferencas
*  de coordenadas entre a posicao atual de Rafael e a ajacente mais o tempo atual for menor do que o tempo
*  adjacente e a resposta ainda nao tiver sido computada, a mesma e acrescida em uma unidade.
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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

struct posicao_maca {
	int x, y, t, res;
};

typedef struct posicao_maca maca;

int main(void) { _
	int i, j, n, m, k, x, y, t, x0, y0;
	vector<maca> macas;
	
	while(1) {
		sc3(n, m, k);

		if(n == 0) break;

		macas.resize(k + 1);

		for(i = 1; i <= k; i++) {
			sc3(x, y, t);

			macas[i].x = x;
			macas[i].y = y;
			macas[i].t = t;
			macas[i].res = -1;	
		}

		sc2(x0, y0);

		macas[0].x = x0;
		macas[0].y = y0;
		macas[0].t = 0;
		macas[0].res = -1;

		//int maximo = -1;		
		for(i = k; i >= 0; i--) {
			macas[i].res = 1;
			for(j = i + 1; j <= k; j++) {
				if(macas[i].t + max(abs(macas[i].x - macas[j].x), abs(macas[i].y - macas[j].y)) <= macas[j].t 
					&& macas[i].res < macas[j].res + 1) {
						macas[i].res = macas[j].res + 1;	
				}
			}
		}
				
		
		//for(i = 0; i <= k; i++) {
		//	if(macas[i].res > maximo) maximo = macas[i].res;
		//}

		pri(macas[0].res - 1);
	}

	return 0;
}
