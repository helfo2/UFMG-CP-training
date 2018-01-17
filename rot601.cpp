/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Não é mais um joguinho canadense
*  Roteiro 6 - Problema 1
*  Estratégias: encarando o problema como uma sequência de estados representados por autômatos,
*  é intuitivo perceber que a soma dos custos de transição acumula-se ao fator de 2 elevado ao 
*  número de caracteres após o b encontrado, para cada b. Isso acontece justamente por só haver
*  dois estados e pela lógica do problema garantir que somente uma vez que se chega ao estado q o
*  valor final se altera dessa forma.
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
	ll valor_final;
	char palavra[61];
	int teste = 1;

	while(scanf("%s", palavra) != EOF) {
		valor_final = 0;

		for(int i = 0; palavra[i] != '\0'; i++) {
			if(palavra[i] == 'b') {
				valor_final += pow(2, (int)strlen(palavra)-(i+1));
				//printf("strlen = %d\n", (int)strlen(palavra)-(i+1));
			}
		}

		printf("Palavra %d\n", teste++);
		printf("%lld\n", valor_final);
	}

	return 0;
}