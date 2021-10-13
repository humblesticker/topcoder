#include <vector>
#include <string>
#include <iostream>
using namespace std;

class DevuAndRabbitNumbering {
public:
	string canRenumber(vector<int> &rabbitIds) {
		vector<int> count(1002, 0), movable(1002, 0);
		for(int id : rabbitIds) { count[id] += 1; movable[id] += 1; }
		
		for(int i=1; i<=1000; i++) {
			if(count[i] > 3) return "cannot";
			
			// check left 
			if(count[i] > 1 && count[i-1] == 0) {
				count[i-1] = 1;
				count[i] -= 1;
			}
			
			// check right  
			if(count[i] > 1 && count[i+1] == 0) {
				count[i+1] = 1;
				count[i] -= 1;
			}
			
			if(count[i] > 1) return "cannot";
		}
		
		return "can";
	}
};

int main() {
    int n; vector<int> ids;
	while(cin >> n) ids.push_back(n);

	DevuAndRabbitNumbering numbering;
	cout << numbering.canRenumber(ids) << endl;
    return 0;
}

/*
check left 
	0 fine 
	1 not moved yet

	if possible commit

check right 
	0 fine
	1 not moved yet 

	if possible commit 	
*/