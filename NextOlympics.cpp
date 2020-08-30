/*
2021.07.23
today: calculate days remaining  

month array from 1 to 12
year, month, day

while date is not same
	add day 
	if day > max for the month day = 1, month++
	if month > 12 month = 1 and year++
	count++

return count
	
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NextOlympics {
	vector<int> Months{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int Year = 2021, Month = 7, Day = 23;

public:
	// todo: you can advance day up to max to optimize
	int countDays(string today) {
		int y = stoi(today.substr(0, 4)), m = stoi(today.substr(5, 2)), d = stoi(today.substr(8, 2)), count = 0;
		while(!(y == Year && m == Month && d == Day)) {
			count++; d++; 
			if(d > Months[m]) { 
				d = 1; 
				m++; if(m > 12) { m = 1; y++; }
			}
		}
		return count;
	}
};

int main() {
	string s; cin >> s;
	NextOlympics no;
	cout << no.countDays(s) << endl;
	return 0;
}