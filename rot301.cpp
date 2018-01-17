/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Popular
*  
*  Roteiro 3 - Problema 1
*  
*  Estrategias: considerou-se como se a entrada fosse a leitura de uma matriz 
*  quadrada e o processamento se reduziu a acumular a quantidade de pontos
*  por coluna e compará-los a fim de concluir qual quantidade era maior
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, i, j, voto, maior_votos;
	vector<int> votos_aluno;

	while(scanf("%d", &n), n > 0) {
		maior_votos = 0;
		
		votos_aluno.resize(n);
		for(i = 0; i < n; i++) votos_aluno[i] = 0;

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &voto);
				
				if(voto) votos_aluno[j]++;
				if(votos_aluno[j] > maior_votos) maior_votos = votos_aluno[j];
			}
		}

		printf("%d\n", maior_votos);
		votos_aluno.clear();
	}

 	return 0;
}