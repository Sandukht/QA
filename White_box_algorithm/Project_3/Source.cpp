#include<iostream>
#include<fstream>
#include <iostream>
#include <algorithm>
#include<numeric> 
#include <bits/stdc++.h>
using namespace std;


bool coprime(int a, int b)
{
	return (__gcd(a, b) == 1);
}


int numOfPairs(int arr[], int n, ofstream& c, ofstream& b)
{ 
	int n = sizeof(arr) / sizeof(arr[0]);
	c << "start" << endl;
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		c << "i=" << i << endl;
		for (int j = i + 1; j < n; j++)
		{
			if (coprime(arr[i], arr[j]))
			{
				count++;
			}
		}
	}
	c << "end" << endl;
	return count;
}



void test_driver(int(*func)(int*, int, ofstream&, ofstream&), std::ifstream& a, std::ofstream& c1, std::ofstream& b1)
{
	
	while (!a.eof()) {
		int x, y, result;
		int* arr = new int[y];
		for (int i = 0; i < y; i++)
		{
			a >> arr[i];

		}
		a >> y;
		a >> result;
		
		if (func(arr, y, c1, b1) == result)
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
	ofstream ofstr, ofstr1;
	ofstr.open("Log1.txt", ios::out);
	ofstr1.open("Log2.txt", ios::out);
	test_driver(numOfPairs, ifstr, ofstr, ofstr1);
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