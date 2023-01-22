#include<iostream>
#include<fstream>
using namespace std;
void test_driver(int(*f)(int*, int), std::ifstream& a, std::ofstream& b) {
	int tox = 0;
	while (!(a).eof()) {
		int len;

		int expected_value;
		a >> len;
		int* arr = new int[len];
		for (int i = 0; i < len; i++) {
			a >> arr[i];
			b << "arr[" << i << "] is " << arr[i] << endl;

		}
		a >> expected_value;
		
		
		b << "\nresult is " << expected_value << "\narr is " << arr << "\n";

		/*if (f(arr, len) == expected_value) {
			b << "test passed\n";
		}
		else {
			b << "test failed\n";
		}*/

		tox++;
		delete[]arr;
	}
	//cout << tox << endl;


}
int chkrkvox(int a[], int n)
{
	int count = 0;
	bool* f = new bool[n];
	for (size_t i = 0; i < n; i++)
	{
		f[i] = true;
	}
	for (size_t i = 0; i < n; i++)
	{
		if (f[i] == false) continue;
		for (size_t j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				f[j] = false;
			}

		}
		count++;
	}
	return count;
}
int main() {
	ifstream istr("TestCases.txt");
	ofstream ostr("Result.txt");
	//int a[5] = { 3, 22 ,23, 23 ,23 };
	//cout << chkrkvox(a, 5) << endl;
	test_driver(chkrkvox, istr, ostr);
	system("pause");
	return 0;
}