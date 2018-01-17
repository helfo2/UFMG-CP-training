/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Divisão da Nlogônia
*  Roteiro 9 - Problema 01
*  Estrategias: lendo o ponto de divisa, sabe-se em que quadrante do plano cartesiano se encontra
*  o ponto informado, a partir de cinco basicas possibilidades: em cima de uma das divisas, no primeiro,
*  segundo, terceiro ou quarto quadrante. Ao compararmos a coordenada abcissa com a origem informadas e
*  assim tambem no caso da coordenada ordenada informada, concluimos em que quadrante o ponto se econtra.
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

int main(void) { _
	int k;

	while(sc(k),k>0){
		int m,n; sc2(n,m);

		while(k--){
			int x,y; sc2(x,y);

			if(x==n||y==m) printf("divisa\n");
			else if(x<n&&y>m) printf("NO\n");
			else if(x>n&&y>m) printf("NE\n");
			else if(x>n&&y<m) printf("SE\n");
			else if(x<n&&y<m) printf("SO\n");
		}
	}

	return 0;
}
