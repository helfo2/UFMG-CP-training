/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Encontre o telefone
*  Roteiro 8 - Problema 2
*  Estratégias: foi feito um hash de conversao, para cada caractere presente na string informada.
*  Daí, lemos a string e verificamos se o caractere é alfanumérico ou não e convertemos conforme o
*  hash quando necessário.
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

int main(void) { _
	string c;
	map<char, int> hash;

	hash['A'] = 2;
	hash['B'] = 2;
	hash['C'] = 2;
	
	hash['D'] = 3;
	hash['E'] = 3;
	hash['F'] = 3;
	
	hash['G'] = 4;
	hash['H'] = 4;
	hash['I'] = 4;

	hash['J'] = 5;
	hash['K'] = 5;
	hash['L'] = 5;

	hash['M'] = 6;
	hash['N'] = 6;
	hash['O'] = 6;

	hash['P'] = 7;
	hash['Q'] = 7;
	hash['R'] = 7;
	hash['S'] = 7;

	hash['T'] = 8;
	hash['U'] = 8;
	hash['V'] = 8;

	hash['W'] = 9;
	hash['X'] = 9;
	hash['Y'] = 9;
	hash['Z'] = 9;

	while(getline(cin, c)) {
		for(int i = 0; i < sz(c); i++) {
			if(isalpha(c[i])) {
				printf("%d", hash[c[i]]);
			}
			else if(c[i] == ' '){
				printf("%c", c[i]);	
			}
			else if(c[i] == '1' || c[i] == '0' || c[i] == '-'){
				printf("%c", c[i]);
			}
		}

		printf("\n");
	}

	return 0;
}
