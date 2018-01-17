/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: UVa 10008 - What's Cryptanalysis?
*  Roteiro 8 - Problema 11
*  Estrategias: a cada linha lida com o getline(), transformou-se a string para letras maiusculas. Iterando sobre a mesma, caso o
*  caractere correspondente fosse uma letra, arescenta-se uma unidade ao seu valor no mapa correspondente, caso ja tivesse sido inserido.
*  Caso contrario, insere-se essa letra com valor incial 1, no mapa. Para ordenar a saida, foi criado um vector de pair assim como o do
*  mapa e o mapa foi copiado para o vetor. Utilizou-se, entao, a funcao sort com a funcao de comparacao cujo criterio de desempate e a ordem
*  alfabetica.
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

bool comp(pair<char, int> a, pair<char, int> b) {
	if(a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main(void) { _
	int n;
	string str;
	map<char, int> letters;
	vector<pair<char, int> > order;

	while(cin >> n) {
		cin.ignore();
		str.clear();

		fr(i, n) {
			getline(cin, str);

			transform(str.begin(), str.end(), str.begin(), ::toupper);
			
			fr(i, sz(str)) {
				if(isalpha(str[i]))
					if(letters.insert(mp(str[i], 1)).second == false) letters[str[i]]++;
			}
		}

		copy(letters.begin(), letters.end(), back_inserter(order));

		sort(order.begin(), order.end(), comp);
		
		vector<pair<char, int> >::iterator it;
		
		tr(order, it) {
			cout << it->first << ' ' << it->second << endl;
		}
	}

	return 0;
}
