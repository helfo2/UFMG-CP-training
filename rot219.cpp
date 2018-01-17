#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

using namespace std;

int main(void) {
	int n, p, temp, op, menor = 1000000000;
	vector<int> armarios;
	vector<int>::iterator it, it2;

	while(1) {
		scanf("%d %d", &n, &p);

		if(n == 0 && p == 0) break;

		menor = 1000000000;

		for(int i = 0; i < p; i++) {
			scanf("%d", &temp);
			armarios.pb(temp);
		}

		tr(armarios, it) {
			it2 = upper_bound(armarios.begin(), armarios.end(), *it);

				
			if(i - (armarios[i] + n - 1) < menor) menor = i - (armarios[i] + n - 1);
		}

		printf("%d\n", menor);
	}
}
