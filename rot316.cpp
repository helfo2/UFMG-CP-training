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
#include <algortihm>

using namespace std;

int main(void) {
	int i, result, flag, a0, a1, a2, a3, a4;
	vector<int> a, op;

	while(scanf("%d %d %d %d %d", &a0, &a1, &a2, &a3, &a4)) {
		flag = 0;

		if(a0 == 0 && a1 == 0 && a2== 0 && a3 == 0 && a4 == 0) break;

		a.resize(5);
		a[0] = a0; a[1] = a1; a[2] = a2; a[3] = a3; a[4] = a4;

		sort(a.begin(), a.end());
		
		op.push_back(a[0] + a[1]);

		do{

		} while(next_permutation(a.begin(), a.end()));

		op.clear();
	}

	return 0;
}
