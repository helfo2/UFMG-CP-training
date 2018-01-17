/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Parque Jurássico
*  Roteiro 12 - Problema 4
*  Estratégias: 
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

void printDiff(vvi& tabela, string& x, string& y, string& lcs, int i, int j) {
    if(i > 0 && j > 0 && x[i] == y[j]) {
        printDiff(tabela, x, y, lcs, i - 1, j - 1);
        printf("%c", x[i]);
    }
    else if(j > 0 && (i == 0 || tabela[i][j - 1] >= tabela[i - 1][j])) {
        printDiff(tabela, x, y, lcs, i, j - 1);
        printf("%c", y[i]);
    }
    else if(i > 0 && (j == 0 || tabela[i][j - 1] < tabela[i - 1][j])) {
        printDiff(tabela, x, y, lcs, i - 1, j);
        printf("%c",  lcs[i]);
    }
    else printf("");
}

string lcs(string& x, string& y){
	int m = sz(x), n = sz(y);
	vvi tabela(m + 1, vi(n + 1));

	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == 0 || j == 0)
				tabela[i][j] = 0;
			else if(x[i - 1] == y[j - 1])
				tabela[i][j] = tabela[i - 1][j - 1] + 1;
			else
				tabela[i][j] = max(tabela[i - 1][j], tabela[i][j - 1]);
		}
	}

	int tam = tabela[m][n];

	string lcs;
	lcs.resize(m + n - tam);
	tam = m + n - tam;
	printf("tam = %d\n", tam);
	lcs[tam] = '\0';

	int i = m, j = n;

	while(i > 0 && j > 0) {
		if(x[i - 1] == y[j - 1]) { // caractere faz parte da lcs
			lcs[tam - 1] = x[i - 1];
			printf("foi x- %c\n", x[i - 1]);
			i--; j--; tam--; // decrementa todos os indices
		}
		else if(tabela[i - 1][j] > tabela[i][j - 1]) { // acha o maior dos numeros adjacentes na tabela
			lcs[tam - 1] = x[i - 1];
			printf("foi x %c\n", x[i - 1]);
			i--; tam--;
		}
		else {
			lcs[tam - 1] = y[j - 1];
			printf("foi y %c\n", y[j - 1]);
			j--; tam--;
		}
	}
	
	printf("tam = %d\n", tam);
	printf("i = %d\n", i);
	printf("j = %d\n", j);
	i = m; j = n;
	printDiff(tabela, x, y, lcs, i, j);

	return lcs;
}

int main(void) {
	string s1, s2, s_lcs, resp;

	while(1) {
		cin >> s1;
		if(s1[0] == '#') break;
		cin >> s2;

		s_lcs = lcs(s1, s2);

		cout << "S1: " << s1 << endl;
		cout << "S2: " << s2 << endl;
		cout << "LCS: " << s_lcs << endl;

		int len1 = sz(s1), len2 = sz(s2), len_lcs = sz(s_lcs);
		
		resp.resize(len1 + len2 - len_lcs);
		int i = 0, j = 0, k = 0;

		/*while(k < len_lcs) {
			while() {
				resp[k++] = s2[j++];
				i = j;
			}
			
			resp[k++] = s1[i++];
			
			else {
				resp[k] = s_lcs[k];
				k++;
			}
		}

		cout << "RESP: " << resp << endl;*/
	}

	return 0;
}