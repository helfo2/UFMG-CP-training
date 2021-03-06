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

const int MAXV = 10033;

using namespace std;

vi grafo[MAXV];
bool visitados[MAXV];

bool dfs(int atual, int pai) {
	visitados[atual] = true;

	for(int filho : grafo[atual]) {
		if(filho == pai) continue;
		if(visitados[filho]) return true;
		if(dfs(filho, atual)) return true;
	}

	return false;
}


int main(void) { _
	int n, m, a, b;
	bool tem_ciclo = false;

	while(sc2(n, m) == 2) {
		for(int i = 1; i <= n; i++) {
			grafo[i].clear();
			visitados[i] = false;
		}

		while(m--) {
			sc2(a, b);
			grafo[a].pb(b);
			grafo[b].pb(a);
		}

		tem_ciclo = false;
		for(int i = 1; i <= n; i++) {
			if(!visitados[i]) {
				if(dfs(i, -1)) { // pai do cara e -1
					tem_ciclo = true;
				}
			}
		}

		if(tem_ciclo) printf("Inseguro\n");
		else printf("Seguro\n");
	}

	return 0;
}
