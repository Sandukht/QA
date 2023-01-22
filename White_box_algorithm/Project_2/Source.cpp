#include <iostream>
#include <fstream>
using namespace std;

void test_driver(bool(*func)(int, int, ofstream&, ofstream&), std::ifstream& d, std::ofstream& c, std::ofstream& b)
{
	int line = 1;
	while (!d.eof()) {
		int x;
		int y;
		bool result;
		d >> x;
		d >> y;
		d >> result;
		if (func(x, y, c, b) == result) {
			b << "test is successfull!\n";
		}
		else {
			b << "test failed!\n";
		}

	}
}
bool funcpow(int x, int y, ofstream& c, std::ofstream& b) {
m1:if (x == 1)
{
	c << "m1 command's true was completed!\n";
	return true;
} c << "m1 command's false was completed!\n";
m2:while (x != 1) {
c << "m2 command's true was completed!\n";
m3:if (x % y != 0) {
c << "m3 command's true was completed!\n";
return false;
}
else {
	c << "m3 command's false was completed!\n";
	x = x / y;
}
}
c << "m2 command's false was completed!\n";
return true;

}

int main() {
	ifstream ifstr;
	ifstr.open("test_cases.txt", ios::in);
	ofstream ofstr, ofstr2;
	ofstr.open("Log.txt", ios::out);
	ofstr2.open("log2.txt", ios::out);

	test_driver(funcpow, ifstr, ofstr, ofstr2);
	system("pause");
	return 0;
}