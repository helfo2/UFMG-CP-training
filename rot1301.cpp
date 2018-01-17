/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Caminho das pontes
*  Roteiro 6 - Problema 5
*  Estratégias: de maneira similar a outros problemas de caminho mínimo, bastou implementar
*  o algoritmo de Dijkstra para percorrer o grafo e retornar o número mínimo de buracos encontrados
*  nas pontes. Importante notar que no grafo se encontram todas as arestas pertencentes ao intervalo [0,...,N+1]
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

struct node{
    int index, parent, cost;    
};
 
/*
   O grafo aqui usa lista de adjacencia para as arestas,
   porem usa matriz de adjacencia para manter os fluxos.
 
   Poderia usar matriz de adjacencia para as arestas também,
   mas deixa a bfs lenta.
*/
 
struct graph{
    vector<int> edges[MAXV];
    node nodes[MAXV];
    int flow[MAXV][MAXV];
    int size;
};
 
bool bfs(graph &g, int a, int b = -1){
    queue< node > q;
    vector<bool> mark(g.size, false);
    q.push(g.nodes[a]);
    while (!q.empty()){
        node v = q.front();
        q.pop();
        if (mark[v.index]) continue;
        mark[v.index] = true;
        g.nodes[v.index] = v;
        if (v.index == b) return true;
        for (int i = 0; i < g.edges[v.index].size(); ++i){
            int j = g.edges[v.index][i];
            if (!mark[j] && g.flow[v.index][j] > 0){
                node tmp = g.nodes[j];
                tmp.cost = v.cost+1;
                tmp.parent = v.index;
                q.push(tmp);
            }
        }
    }
    return false;
}
 
 
/* inicializacao do grafo quanto ao numero de vertices */
 
void init(graph &g, int v){
    g.size = v;
    for (int i = 0; i < v; ++i){
        g.edges[i].clear();
        g.nodes[i].index = i;
        g.nodes[i].parent = -1;
        g.nodes[i].cost = 0;
        
        for(int j = 0; j < v; ++j) 
            g.flow[i][j] = 0;
    }
}
 
int path_min_capacity(graph &g, int source, int sink){
    node actual = g.nodes[sink];
    int min_capacity = INT_MAX;
 
    while (actual.parent != -1){
        min_capacity = min(min_capacity, g.flow[actual.parent][actual.index]);
        actual = g.nodes[actual.parent];
    }
 
    return min_capacity;
}
 
void path_augment(graph &g, int source, int sink, int min_capacity){
    node actual = g.nodes[sink];
 
    while (actual.parent != -1){
        g.flow[actual.parent][actual.index] -= min_capacity;
        g.flow[actual.index][actual.parent] += min_capacity;
        actual = g.nodes[actual.parent];
    }
}
 
/* EDMONDS KARP (fluxo máximo) */
 
int maxFlow(graph &g, int source, int sink){
    int result = 0, tmp = 0;
    while (true){
        if (!bfs(g, source, sink)) break;
        tmp = path_min_capacity(g, source, sink);
        result += tmp;
        path_augment(g, source, sink, tmp);
    }
    return result;
}
 
/*
   Suponha o seguinte grafo bi-partido em que queremos
   calcular o matching:
   a -> c
   a -> d
   b -> c
 
   Logo vamos adicionar dois nós, um source e um sink,
   e iremos colocar a capacidade das arestas como 1
   para haver matching apenas de 1 para 1 no grafo.
 
Considerando:
    source = 0
    a = 1
    b = 2
    c = 3
    d = 4
    sink = 5
 
Fazemos:
*/
 
graph g;
 
int main(){
    int n = 4;
    init(g, n+2);
 
    g.edges[0].push_back(1); // Adiciona a aresta de 0 para 1
    g.edges[1].push_back(0); // NAO SE ESQUECA DE ADICIONAR A ARESTA DE VOLTA: caso esqueca o algoritmo
                             // nao sera capaz de corrigir o fluxo e a resposta ficará incorreta.
    g.flow[0][1] = 1;        // Altere a capacidade da aresta via a matriz de adjacencia 'flow' 
 
    g.edges[0].push_back(2);
    g.edges[2].push_back(0);
    g.flow[0][2] = 1;
 
    g.edges[1].push_back(3);
    g.edges[3].push_back(1);
    g.flow[1][3] = 1;
 
    g.edges[1].push_back(4);
    g.edges[4].push_back(1);
    g.flow[1][4] = 1;
 
    g.edges[2].push_back(3);
    g.edges[3].push_back(2);
    g.flow[2][3] = 1;
 
    g.edges[3].push_back(5);
    g.edges[5].push_back(3);
    g.flow[3][5] = 1;
 
    g.edges[4].push_back(5);
    g.edges[5].push_back(4);
    g.flow[4][5] = 1;
 
    cout << maxFlow(g, 0, n+1) << endl; //rode o fluxo entre o source e o sink
 
    return 0;
}

void add(grafo& g, grafo& rg, int m) {
	int a, b, time;

	while(m-- > 0) {
		sc3(a, b, time);
		g.adiciona_aresta(a, b, time);
		rg.adiciona_aresta(a, b, time);
	}
}

int main(void) {
	int n, e, t, m, sum = 0;

	sc(n); sc(e); sc(t); sc(m);
	
	grafo g(n);
	grafo rg(n);

	add(g, rg, m);

	for(int i = 1; i < n; i++)
		sum += g.calcula_menor_caminho(e, i, t);

	pri(sum);

	return 0;
}