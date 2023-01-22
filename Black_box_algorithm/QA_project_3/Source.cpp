#include <iostream>
#include <fstream>
using namespace std;
void test_driver(void(*sort)(int*, int), std::ifstream& a, std::ofstream& b) {
	while (!a.eof()) {
		int len;
		a >> len;
		cout << len;
		int* arr = new int[len];
		for (int i = 0; i < len; i++) {
			a >> arr[i];
			cout << "test1\n";
		}
		int* brr = new int[len];
		for (int i = 0; i < len; i++) {
			a >> brr[i];
			cout << "test2\n";
		}
		cout << "test\n";
		sort(arr, len);
		bool test = true;
		for (int j = 0; j < len; j++) {
			if (arr[j] != brr[j]) {
				b << "test failed\n";
				test = false;
				break;
			}
		}
		if (test == true) {
			b << "test succeed!\n";
		}

	}

}
void bubblesort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[i] > a[j]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}
int main() {
	ifstream a;
	a.open("test_case.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(bubblesort, a, b);
	system("pause");
	return 0;
}