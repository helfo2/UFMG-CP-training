/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Dentista
*  Roteiro 4 - Problema 5
*  Estratégias: por solucao gulosa, entendeu-se o problema como um de ordenacao de vetores de pares, com o horario de termino 
*  da consulta enquanto pre-processamento. Assim, bastou comparar o horario de inicio da consulta atual com o horario
*  de termino da ultima consulta aceita, sendo que a primeira consulta, tendo em vista a ordenacao, e sempre aceita.
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

bool compara_termino(const ii& a, const ii& b) {
	return (a.second < b.second);
}

int main(void) {
	int n, x, y, ultimo, consultas = 0;
	ii temp;

	sc(n);

	vii horarios(n);

	for(int i = 0; i < n; i++) { // preenche vetor
		sc2(x, y);

		horarios[i] = mp(x, y);
	}

	sort(horarios.begin(), horarios.end(), compara_termino);

	ultimo = horarios[0].second;
	temp = horarios[0];

	consultas++;

	for(int i = 1; i < n; i++) {
		//printf("ulitmo = %d\n", ultimo);
		//printf("temp = %d %d\n", temp.first, temp.second);

		//printf("atual = %d %d\n", horarios[i].first, horarios[i].second);

		if(horarios[i] != temp) {
			if(horarios[i].first >= ultimo) {
				//printf("consultas++\n");
				consultas++;
				
				ultimo = horarios[i].second;
				temp = horarios[i];
			}
		}

		//printf("\n\n\n");
	}

	pri(consultas);
	return 0;
}