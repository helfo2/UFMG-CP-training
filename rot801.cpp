/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Poodle
*  Roteiro 8 - Problema 1
*  Estratégias: verficar a razao entre a quantidade total de resultados e os
*  resultados disponiveis por pagina. Caso seja maior que 20, sabemos que so 
*  podem haver 16 letras o. Caso seja menor que 6, entao temos o caso padrao
*  com 2 letras o. Entre os dois limites, entao de fato escrevemos quantas letras
*  o forem a quantidade de paginas.
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
	float n, p, razao;
	int qnt_o;

	while(1) {
		scanf("%f %f", &n, &p);

		if(n == 0 && p == 0) break;

		razao = n / p;

		qnt_o = ceil(razao);

		//printf("qnt_o = %d\n", qnt_o);

		if(qnt_o >= 20) qnt_o = 16;
		else if(qnt_o < 6) qnt_o = 2;
		else qnt_o -= 4;

		printf("P");
		for(int i = 1; i <= qnt_o; i++) {
			printf("o");
		}

		printf("dle\n");
	}

	return 0;
}