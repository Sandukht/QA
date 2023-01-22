#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

double func(int x) {
	double s = sin(x);
	return s;
}

void test_driver(double(*f)(int), std::ifstream& a, ofstream& b)
{

	while (!a.eof())

	{
		double tiv;
		double result;
		a >> tiv;
		a >> result;
		


		if (f(tiv) == result)
		{
			b << "test sucssed!\n";
		}
		else
		{
			b << "test failed!\n";
		}
	}

}

int main()
{
	ifstream a;
	a.open("test_case.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(func, a, b);
	a.close();
	b.close();
	system("pause");
	return 0;
}
