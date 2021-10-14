#include <vector>
#include <string>
#include <iostream>
using namespace std;

class DevuAndRabbitNumbering {

	vector<int> count, movable;

	bool check(int i, int d) {
		while(i + d >= 0 && i + d < count.size()) {
			if(count[i+d] == 0) return true;
			if(movable[i+d] == 0) return false; // count[i+d] = 1
			i += d;
		}
		return false;
	}

	void move(int i, int d) {
		while(i + d >= 0 && i + d < count.size()) {
			count[i] -= 1; movable[i] -= 1; 
			count[i+d] += 1; if(count[i+d] == 1) return;
			i += d;
		}
	}

public:
	string canRenumber(vector<int> &rabbitIds) {	
		count.resize(1002, 0); movable.resize(1002, 0);
		for(int id : rabbitIds) { count[id] += 1; movable[id] += 1; }
		
		for(int i=1; i<=1000; i++) {
			if(count[i] > 3) return "cannot";

			// 2 or 3
			if(count[i] > 1 && check(i, -1)) 
				move(i, -1);

			if(count[i] > 1 && check(1, 1)) 
				move(i, 1);

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
1 2 3 4
1 2 2 4     (0, 0, 0) (1, 1, 1) (2, 2, 2) (3, 0, 0) (4, 1, 1)
					  (1, 2, 1)	(2, 1, 1)
			(0, 1, 0) (1, 1, 0)

1 2 2 2 3   (0, 0, 0) (1, 1, 1) (2, 3, 3) (3, 1, 1) (4, 0, 0)
					  (1, 2, 1)	(2, 2, 2)
					  			(2, 1, 1) (3, 2, 1)
								  	      (3, 1, 0) (4, 1, 0)	
*/