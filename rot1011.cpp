/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: TDA Racional
*  Roteiro 10 - Problema 11
*  Estrategias: bastou ler os números como inteiros, no padrão formatado conforme a entrada e trabalhá-los de acordo com as
*  fórmulas especificadas, através de um switch. Para verificar a possibilidade de simplificação, optou-se pelo MDC recursivo,
*  de implementação mais simples.
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

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

int main(void) { _
	int n;
	int n1, d1, n2, d2, n3, d3;
	int mdc3;
	char op;

	sc(n);

	while(n--) {
		scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

		switch(op) {
			case '+': n3 = (n1 * d2) + (n2 * d1);
					  d3 = d1 * d2;
					  break;
			case '-': n3 = (n1 * d2) - (n2 * d1);
					  d3 = d1 * d2;
					  break;
			case '*': n3 = n1 * n2;
					  d3 = d1 * d2;
					  break;
			case '/': n3 = n1 * d2;
					  d3 = n2 * d1;
					  break;
			default: break;
		}

		printf("%d/%d", n3, d3);

		mdc3 = abs(mdc(n3, d3));

		if(mdc3 == 1)
			printf(" = %d/%d\n", n3, d3);
		else
			printf(" = %d/%d\n", n3 / mdc3, d3 / mdc3);
	}

	return 0;
}
