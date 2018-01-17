/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Coordenadas de um ponto
*  URI 1041
*  Estrategias: bastou verificar os pares de coordenadas em
*  7 casos diferentes: x = 0 e y = 0 -> origem; 
*  x = 0 e y != 0 -> eixo Y; x != 0 e y = 0 -> eixo X
*  e assim por diante.
*/
#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int t, m, d, c, resp, qnt, temp;
	unsigned int chave, todas_chaves, todos_diretores;
	set<int> diretores;

	scanf("%d", &t);

	while(t-- > 0) {
		todos_diretores = 0;	
		qnt = 0;
		scanf("%d %d", &m, &d);

		while(d-- > 0) {
			scanf("%d", &c);
			//printf("c = %d\n", c);
			temp = 1;
			todas_chaves = 0;

			while(c-- > 0) {
				scanf("%d", &chave);
				if(temp == 1 && diretores.size() < m && diretores.find(chave) == diretores.end()) {
					temp = 0;
					qnt++;
				}
				diretores.insert(chave);
				todas_chaves |= chave;
			}

			todos_diretores |= todas_chaves;
		}

		//for(set<int>::iterator it = diretores.begin(); it != diretores.end(); it++) cout << *it << " ";
		resp = __builtin_popcount(todos_diretores);
		
		printf("resp = %d\n", resp);
		//printf("size = %d\n", (int)diretores.size());

		if(diretores.size() < m) printf("Desastre!\n");
		else printf("%d\n", qnt);

		diretores.clear();
	}

	return 0;
}