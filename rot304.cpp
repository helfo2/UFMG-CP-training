/* Nome: Henrique Eustaquio Lopes Ferreira
*  Matricula: 2015068990
*  Problema resolvido: Candy
*  
*  Roteiro 3 - Problema 4
*  
*  Estrategias: após armazenar cada quantidade de doces em um vetor de pacotes,
*  a ideia foi verificar se o total de doces era divisível pelo número de crianças,
*  garantindo que todas receberiam a mesma quantidade. Caso positivo, bastou somar
*  as diferenças entre o excesso de doces em cada pacote e a quantidade correta. 
*  Caso contrário, escreve-se -1.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int i, n, candies, sum, equal_amount, moves;
	vector<int> packets;

	while(scanf("%d", &n), n != -1) {
		sum = 0;
		packets.resize(n);

		for(i = 0; i < n; i++) {
			scanf("%d", &candies);
		
			sum += candies;

			packets[i] = candies;
		}

		if(sum % n == 0) {
			equal_amount = sum / n;
			moves = 0;

			for(i = 0; i < n; i++) {
				if(packets[i] > equal_amount)
					moves += packets[i] - equal_amount;
			}

			printf("%d\n", moves);
		} else printf("-1\n");
	}

 	return 0;
}