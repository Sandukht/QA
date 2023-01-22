#include <iostream>
#include <fstream>
using namespace std;

void test_driver(int(*f)(int*, int), std::ifstream& a, std::ofstream& b) {
	int tox = 0;
	while (!(a).eof()) {
		int len;

		int result;
		a >> len;
		int* arr = new int[len];
		for (int i = 0; i < len; i++) {
			a >> arr[i];

		}
		a >> result;
		if (f(arr, len) == result) {
			b << "test sucssed"<<tox<<"angam\n";
		}
		else {
			b << "test failed"<<tox<<"angam\n";
		}

		tox++;
	}
	cout << "tox is "<<tox << endl;


}
int mutant2(int* a, int n) {
	cout << "hiiiiiii" << endl;
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] * a[i + 1] >= 0) {
			cout<<"test\n";

		}
		else {
			count++;
		}
	}

	return count;
}
int mutant1(int* a, int n) {
	cout << "GGGGGGGGGGGGGGGGGGG" << endl;
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] * a[i + 1] < 0) {
			count++;
		}

	}

	return count;
}

int main() {
	ifstream a;
	a.open("testcases.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(mutant2, a, b);
	system("pause");
	return 0;
}
