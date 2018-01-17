#include <iostream>
#include <list>
#include <stack>
#include <cstdlib>

using namespace std;

class grafo {
public:
	int N; 
	list<int> *adj;

	grafo(int v); 
	void adiciona_aresta(int v1, int v2);
	int dfs(int v);
};

grafo::grafo(int n) {
	this->N = n;
	adj = new list<int>[N * (N - 1)];
}

void grafo::adiciona_aresta(int v1, int v2) {
	adj[v1].push_back(v2);
}

int grafo::dfs(int v) {
	stack<int> aux;
	int visitados[N+1], achou; 
	int cont = 0;
	list<int>::iterator it;

	for(int i = 1; i <= N; i++) visitados[i] = 0;
 
	while(1){
		if(!visitados[v]){
			visitados[v] = 1;
			cont++;

			aux.push(v);
		}
 
		achou = 0;

		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(*it != v && !visitados[*it]){
				achou = 1;
				break;
			}
		}
 
		if(achou) v = *it;
		else{
			aux.pop();
			
			if(aux.empty()) break;
			
			v = aux.top();
		}
	}

	if(cont != N) return 0;
	return 1;
}

void adiciona_ruas(grafo& cidade, int m) {
	int v, w, p;

	while(m-- > 0) {
		scanf("%d %d %d", &v, &w, &p);

		cidade.adiciona_aresta(v, w);
		if(p == 2) cidade.adiciona_aresta(w, v);
	}
}

int main(void) {
	int i, n, m, v, w, p, conexidade;

	while(scanf("%d %d", &n, &m), n > 0) {
		grafo cidade(n);

		adiciona_ruas(cidade, m);

		conexidade = 1;
		for(i = 1; i <= n; i++) {
			if(!cidade.dfs(i)) {
				conexidade = 0;
				break;
			}
		}

		cidade.adj = NULL;
		free(cidade.adj);


		printf("%d\n", conexidade);
	}

	return 0;
}