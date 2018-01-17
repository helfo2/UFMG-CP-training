#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(void) {
	int n, i, temp, pontos, c, par, par1, par2, consec, teste = 1, trinca, flag;
	vector<int> mao;
	map<int, int> qnt;
	vector<int>::iterator it;
	
	scanf("%d", &n);

	while(n-- > 0) {
		pontos = 0;
		c = 0;
		mao.resize(5);

		scanf("%d %d %d %d %d", &mao[0], &mao[1], &mao[2], &mao[3], &mao[4]);

		sort(mao.begin(), mao.end());

		for(i = 1; i <= 13; i++) {
			temp = count(mao.begin(), mao.end(), i);
			
			if(temp != 0) {
				qnt[i] = temp;
				c++;
			}
			else qnt[i] = 0;
		}

		
		if(c == 2) {
			flag = 0;

			for(i = 1; i <= 13; i++) {
				if(qnt[i] == 4) {
					temp = i;
					flag = 1;
					break;
				}
				else if(qnt[i] == 3) trinca = i;
			}

			if(flag) {
				it = lower_bound(mao.begin(), mao.end(), temp);
				pontos = 180 + *it;
			} else {
				it = lower_bound(mao.begin(), mao.end(), trinca);
				pontos = 160 + *it;
			}
			
			
		} 
		else if(c == 3) {
			par = 0;
			par1 = 0;
			par2 = 0;

			for(i = 1; i <= 13; i++) {
				if(qnt[i] == 2) {
					par++;
					if(par1 <= par2) par1 = mao[i];
					else par2 = mao[i];
				}
				else if(qnt[i] == 3){
					pontos = 140 + mao[i];
					break;
				}
			}

			if(par == 2) {
				if(par1 < par2) pontos = 3*par1 + 2*par2 + 20;
				else pontos = 3*par2 + 2*par1 + 20;
			}
		}
		else if(c == 4) {
			for(i = 1; i < 5; i++) {
				if(mao[i] == 2) {
					pontos = mao[i];
					break;
				}
			}
		}
		else if(c == 5) {
			consec = 1;

			for(i = 1; i < 5; i++) {
				if(mao[i] < mao[i-1]) {
					consec = 0;
					break;
				}
			}

			if(consec) pontos = 200 + mao[0];
			else pontos = 0;
		}

		printf("Teste %d\n%d\n", teste++, pontos);

		mao.clear();
		qnt.clear();
	}

	return 0;
}