#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

using namespace std;

int main(void) {
	int n, x, max = 0;
	pair<int, int> temp;
	map<int, int> votos;

	for(int i = 0; i < n; i++) {
		if(votos.find(x) != votos.end()) {
			temp.first = x;
			temp.second = 1;
			map.insert(temp);
		}
		else {
			map[x]++;
		}

		if(map[i] > max) {
			max = map[i];
		}
	}

	cout << max;
}
