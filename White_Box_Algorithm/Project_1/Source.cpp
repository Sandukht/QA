#include <iostream>
#include <fstream>
using namespace std;
void test_driver(bool(*func)(int, ofstream&), std::ifstream& d, std::ofstream& c)
{
	int line = 1;
	while (!d.eof()) {
		int x;
		d >> x;
		func(x, c);
	}
}

bool parz(int a, ofstream& c)
{
	int i, b;
	if (a == 1) {
		b = 2 * a; // b=2

		c << "1 is completed\n";
		return false;
	}
	for (i = 2, c << "2 is completed\n"; i * i <= a; i++, c << "5 is completed\n") {
		if (a % i == 0) {
			b = 3 * a; // b= 6
			c << "4 is completed\n";
			return false;
		}
	}

	b = 6 * a; // b= 48
	c << "3 is completed\n";
	return true;
}

int main()
{
	ifstream ifstr;
	ifstr.open("test_case.txt", ios::in);
	ofstream ofstr;
	ofstr.open("Log.txt", ios::out);

	test_driver(parz, ifstr, ofstr);
	return 0;

}