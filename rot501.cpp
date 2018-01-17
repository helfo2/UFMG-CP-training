#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct no{
    int index, visitado;
};
 
struct grafo{
    vector<no> nos;
    vector<vector<int> > arestas;
};
 
void inicializa_grafo(grafo &g, int n){
    g.nos.resize(n);
    g.arestas.resize(n);
 
    for(int i = 0; i < n; i++){
        g.nos[i].index = i;
        g.nos[i].visitado = i;
        g.arestas[i].resize(n, 0); //adicione esta linha para matriz de adjacencia
    }
}

void dfs(grafo& matriz, int i, int n){
    matriz.nos[i].visitado = 1;

    for(int k = 0; k < n; k++) {
        if(matriz.arestas[i][k] == 1 && matriz.nos[k].visitado == 0) {
            dfs(matriz, k, n);
        }
    }
}

int main(void){
    int n, m, v, w, p, flag, conta;
    
    grafo cidade;

    while(scanf("%d %d", &n, &m), n > 0) {
        inicializa_grafo(cidade, n);
        
        while(m-- > 0) {
            scanf("%d %d %d", &v, &w, &p);

            cidade.arestas[v - 1][w - 1] = 1;
            if(p == 2) cidade.arestas[w - 1][v - 1] = 1;
        }

        flag = 1;
        cont = 0;
        for(int i = 0; i < n; i++) {
            dfs(cidade, i, n);

            if() {
                flag = 0;
                break;
            }
        }

        if(flag) printf("1\n");
        else printf("0\n");

        cidade.nos.clear();
        cidade.arestas.clear();
    }

    return 0;
}