/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Bits trocados
*  Roteiro 4 - Problema 2
*  Estratégias: considerando-se a solucao otima gulosa referente a subtrair do numero
*  valores maiores das notas ate que o mesmo termine com o valor 0, ela foi implementada
*  com o uso de dois whiles, o exterior de controle de entrada e o interior responsavel pelo
*  processamento descrito.
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
	int v, n = 1, i, j, k, l;

	sc(v);

	while(v != 0) {
		i = 0; j = 0; k = 0; l = 0;
		
		while(v != 0) {
			if(v >= 50) {
				i++;
				v-=50;	
			}
			else if(v >= 10){
				j++;
				v-=10;
			}
			else if(v >= 5){
				k++;
				v-=5;
			}
			else if(v >= 1){
				l++;
				v-=1;
			}
		}

		printf("Teste %d\n%d %d %d %d\n\n", n++, i, j, k, l);

		sc(v);
	}

	return 0;
}