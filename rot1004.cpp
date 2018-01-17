/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Você pode dizer 11
*  Roteiro 10 - Problema 13
*  Estrategias: ao ler o numero como uma string, percorreu-se a mesma somando-se as posições de maneira intercalada. Daí, tirando-se
*  a diferença entre uma soma e outra e verificando se ela é divisível por 11, temos a resposta do problema, na saída devidamente
*  formatada de acordo com o enunciado.
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
#define tr(c,i) for(decltype((c).begin()) i = (c).begin(); i != (c).end(); i++) 
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

unsigned ll fatorial, temp;

void fat(int n) {
	fatorial = 1;

	for(int i = 1; i <= n; i++) {
		fatorial = (fatorial % 100000) * i;

		temp = fatorial;
		while(temp > 0) {
			if(temp % 10 == 0) temp /= 10;
			
		}
	}
}

int main(void) { _
	int n, k;

	while(sc(n) != EOF) {
		
		fat(n);



		printf("Instancia %d\n%d", ++k, fatorial);
	}

	return 0;
}
