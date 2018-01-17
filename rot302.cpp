/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Heads or Tails
*  
*  OBS.: login do aluno no CodeForces: henr_0352
*
*  Roteiro 3 - Problema 2
*  
*  Estrategias: a solucao consistiu em iterar considerando os limites informados
*  na entrada, printando a resposta na saida padrao, considerando os casos em que
*  Vasya ganha, ou seja, i é estritamente maior do que j. Interessante notar que 
*  um vetor de pares foi escolhido por ser a estrutura mais simples capaz de representar
*  com precisão a saída do programa, até mesmo por conter a quantidade de possibilidades
*  de jogadas em seu size().
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
 	int x, y, a, b, qnt_jogadas;
 	pair<int, int> jogada;
 	vector<pair<int, int> > jogo;

 	scanf("%d %d %d %d", &x, &y, &a, &b);
 	for(int i = a; i <= x; i++) {
 		for(int j = b; j <= y; j++) {
 			if(i > j) {
	 			jogada.first = i;
	 			jogada.second = j;
	 			jogo.push_back(jogada);
 			}
 		}
 	}

 	qnt_jogadas = jogo.size();
 	printf("%d\n", qnt_jogadas);
 	
 	for(int cont = 0; cont < qnt_jogadas; cont++) {
 		printf("%d %d\n", jogo[cont].first, jogo[cont].second);
 	}

 	return 0;
}