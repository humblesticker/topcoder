/*
2021.07.23
today: calculate days remaining  
*/
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class NextOlympics {
	const string Olympic = "2021.07.23";

public:
	int countDays(string today) {
		struct tm now = { 0 }, start = { 0 };
   		strptime(today.c_str(), "%Y.%m.%d", &now);
   		strptime(Olympic.c_str(), "%Y.%m.%d", &start); 
		   
        return difftime(mktime(&start), mktime(&now)) / (24 * 60 * 60);
	}
};

int main() {
	NextOlympics no;
	cout << no.countDays("2020.07.24") << endl;
	return 0;
}