/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: A Needle in the Haystack
*  Roteiro 8 - Problema 6
*  Estratégias: aplicou-se o algoritmo de KMP para o padrao informado e o texto. Foram
*  usadas estrategias diferentes das sugeridas no enunciado do problema, ja que C++ e
*  uma linguagem poderosa para a manipulacao de strings, nao sendo sequer necessario
*  preocupar com o tamanho da entrada.
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

void calcula_prefixos(string padrao, vi& prefixo);

bool kmp(string padrao, string texto) {
	int m = padrao.length(), n = texto.length();
	bool encontrei = false;

	vi prefixo(m);

	calcula_prefixos(padrao, prefixo);

	int i = 0, j = 0;
	while(i < n) {

		if(padrao[j] == texto[i]) {
			j++;
			i++;
		}

		if(j == m) {
			encontrei = true;
			pri(i - j);
			j = prefixo[j - 1];
		}
		else if(i < n && padrao[j] != texto[i]) {
			if(j != 0) 
				j = prefixo[j - 1];
			else 
				i = i + 1;
		}
	}

	return encontrei;
}

void calcula_prefixos(string padrao, vi& prefixo) {
	int len = 0, m = sz(padrao);

	prefixo[0] = 0;

	int i = 1;
	while(i < m) {
		if(padrao[i] == padrao[len]) {
			len++;
			prefixo[i] = len;
			i++;
		} else {
			if(len != 0) {
				len = prefixo[len - 1];
			} else {
				prefixo[i] = 0;
				i++;
			}
		}
	}
}

int main(void) { _
	string padrao, texto;
	int n;

	while(cin >> n) {
		//cout << "n = " << n << endl;
		cin.ignore();
		getline(cin, padrao);
		getline(cin, texto);
		
		//cout << "padrao = " << padrao << endl;
		//cout << "texto = " << texto << endl;

		if(!kmp(padrao, texto)) {
			cout << endl;
		}
	}

	return 0;
}
