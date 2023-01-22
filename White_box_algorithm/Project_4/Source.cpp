#include<iostream>
#include<fstream>
using namespace std;

int Factor(int x, int y,ofstream&c, ofstream& b)
{
	if (x == 0 || y == 0)
	{
		c << "a is completed\n**************************************\n";
		return -1;
	}
	bool xStatement = false;
	bool yStatement = false;
	while (x != y)
	{
		if (x > y)
		{
			x = x - y;
			c << "c is completed\n";
			return x;
		}
		else
		{
			y = y - x;
			c << "d is completed\n";
			return y;
		}
	}

	c << "b is completed\n**************************************\n";

	return x;
}

void test_driver(int(*func)(int, int,ofstream&, ofstream&), std::ifstream& a, std::ofstream& c1, std::ofstream& b1)
{
	int line = 1;
	while (!a.eof()) {
		int x, y, result;
		a >> x;
		a >> y;
		a >> result;
		//func(x, y, c1, b1);
		if (func(x, y,c1, b1) == result)
		{
			b1 << "test succed!" << endl;
		}
		else {
			b1 << "test failed!" << endl;
		}
		
	}
}

int main()
{
	ifstream ifstr;
	ifstr.open("TC.txt", ios::in);
	ofstream ofstr,ofstr1;
	ofstr.open("Log.txt", ios::out);
	ofstr1.open("log1.txt", ios::out);
	test_driver(Factor, ifstr, ofstr,ofstr1);
	return 0;
}



//int Factor(int x, int y, ofstream  &b)
//{
//	if (x == 0 || y == 0)
//	{
//		b << "mekn u meky 0 e katarvec return -1\n";
//		return -1;
//	}
//	bool xStatement = false;
//	bool yStatement = false;
//	while (x != y)
//	{
//		if (x > y)
//		{
//			x = x - y;
//			xStatement = true;
//		}
//		else
//		{
//			y = y - x;
//			yStatement = true;
//		}
//	}
//	if (xStatement)
//		b << "x = x - y katarvec gone 1 angam\n";
//
//	if (yStatement)
//		b << "y = y - x katarvec gone 1 angam\n";
//
//	b << "Hashvvec amenamec yndhanur bazhanarary veradardz\n";
//	return x;
//}
//
//void test_driver(int(*func)(int, int, ofstream&), std::ifstream &a, std::ofstream  &b)
//{
//	int line = 1;
//	while (!a.eof()) {
//		int x, y;
//		a >> x;
//		a >> y;
//		func(x, y, b);
//	}
//}
//
//int main()
//{
//	ifstream ifstr;
//	ifstr.open("TC.txt", ios::in);
//	ofstream ofstr;
//	ofstr.open("Log.txt", ios::out);
//
//	test_driver(Factor, ifstr, ofstr);
//	return 0;
//}