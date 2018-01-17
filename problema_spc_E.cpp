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

priority_queue<ii, vector<ii>, greater<ii> > pq;

vii grafo[MAXV];
int dist[MAXV];

void dij(int b/*, int e*/){
	memset(dist, INF, sizeof(dist));
	dist[b] = 0;
	pq.p(mp(b, 0));

	while(!pq.empty()){
		auto topo = pq.top();
		pq.pop();
		int u = topo.second;
		int w = topo.first;
		//if(dist[u] == INF) continue;
		for(auto v: grafo[u]){
			if(dist[v.first] > dist[u] + v.second){
				dist[v.first] = dist[u] + v.second;
				pq.p(mp(dist[v.first], v.first));
			}
		}
	}

	//return dist[e];
}

int main() {
	int n, m, q;

	while(sc3(n, m, q) == 3) {
		int x, max_dist;
		for(int i = 0; i <= n; i++) {
			grafo[i].clear();
		}

		for(int i = 0; i < m; i++) {
			int a, b, w; sc3(a, b, w);
			grafo[a].pb(mp(b, w));
			grafo[b].pb(mp(a, w));
		}

		while(q--) {
			sc(x);
			grafo[0].pb(mp(x, 0));
		}

		dij(0);

		max_dist = -1;
		for(int i=1;i<=n;i++) {
			//printf("dist[%d] = %d\n", i, dist[i]);
			if(dist[i]>=max_dist) max_dist=dist[i];
		}
		
		pri(max_dist);
	}

	return 0;
}
