/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Meteoros
*  Roteiro 9 - Problema 03
*  Estrategias: com os pontos superior esquerdo e inferior direito informados, 
*  sabemos se um novo ponto se encontra dentro do retangulo pela logica de sua
*  coordenada X ser maior do que o canto superior esquerdo e menor do que o inferior direito
*  e sua coordenada Y ser maior do que o canto inferior direito e menor do que o canto
*  superior esquerdo (acrescenta-se a condicao igual pelo enunciado do problema).
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
#define sc4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
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

ii sup_e, inf_d;

bool dentro_fazenda(int x, int y) {
	if(x >= sup_e.first && x <= inf_d.first &&
	   y >= inf_d.second && y <= sup_e.second) return true;
	return false;
} 

int main(void) { _
	int x1, x2, y1, y2, teste = 0;

	while(sc4(x1, y1, x2, y2) == 4) {
		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;

		sup_e = mp(x1, y1); inf_d = mp(x2, y2);

		int n; sc(n);
		int meteoritos = 0;
		while(n--){
			int x, y; sc2(x, y);
			if(dentro_fazenda(x, y)) meteoritos++;
		}

		printf("Teste %d\n%d\n", ++teste, meteoritos);
	}

	return 0;
}
