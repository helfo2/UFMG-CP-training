/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Pontos
*  Roteiro 9 - Problema 02
*  Estrategias: ao armazenarmos todos os pontos, calculamos as distancias respectivas e
*  comparamo-las umas com as outras, em complexidade O(n2).
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

double dist(ii p1, ii p2) {
	double dif_x, dif_y;

	dif_x = (double)abs(p1.first - p2.first);
	dif_y = (double)abs(p1.second - p2.second);

	return sqrt(dif_x*dif_x + dif_y*dif_y);
}

int main(void) { _
	int n; sc(n);
	vii pontos(n);

	fr(i, n){
		int x, y; sc2(x, y);
		pontos[i] = mp(x, y);
	}

	double menor = INF;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) { 
			menor = min(menor, dist(pontos[i], pontos[j]));
		}
	}

	if(menor!=INF) printf("%.3f\n", menor);
	else printf("0\n");

	return 0;
}
