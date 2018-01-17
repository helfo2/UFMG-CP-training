#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
#include <numeric>

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

using namespace std;

int main(void) {
	int n = 0, soma = 0, count = 0;
	vector<int> pontos;
	vector<int>::iterator p1, p2;
	
	while(scanf("%d", &n) != EOF) {
		soma = 0;
		count = 0;
		pontos.clear();
		pontos.resize(n);

		for(int i = 0; i < n; i++) {
			scanf("%d", &pontos[i]);
		}
		
		soma = accumulate(pontos.begin(), pontos.begin(), 0);
		
		for(int i = 0; i < n; i++) {

			p1 = lower_bound(pontos.begin(), pontos.end(), pontos[i] + (soma / 3));
			p2 = lower_bound(pontos.begin(), pontos.end(), pontos[i] + (2 * (soma / 3)));

			if(p1 != pontos.end() && p2 != pontos.end()) {
				count++;
			}
		}

		cout << count << endl;
	}
}
