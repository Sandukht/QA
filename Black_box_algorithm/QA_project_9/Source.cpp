#include <iostream>
#include <fstream>
using namespace std;

bool IsPrime(int num)
{
	if (num <= 1)
		return false;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			cout << "false\n";
			return false;
	}
	cout << "true\n";
	return true;
}

int main() {
	ifstream istr;// ("TestCases.txt");
	istr.open("TestCases.txt", ios::in);
	ofstream ostr;// ("Results.txt");
	ostr.open("Results.txt", ios::out);
	int num[2];

	while (!istr.eof())
	{
		istr >> num[0] >> num[1];
		if (IsPrime(num[0]) != num[1])
			ostr << num[0] << " Failed\n";
		else
			ostr << num[0] << " Passed\n";
	}

	istr.close();
	ostr.close();
	system("pause");
	return 0;
}

