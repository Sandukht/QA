#include <iostream>
#include <fstream>
using namespace std;
void test_driver(void(*f)(int*, int, int), std::ifstream& a, std::ofstream& b) {
	while (!a.eof()) {
		int len;

		a >> len;

		int* arr1 = new int[len];
		for (int k = 0; k < len; k++) {
			a >> arr1[k];
		}
		int* brr1 = new int[len];
		for (int l = 0; l < len; l++) {
			a >> brr1[l];
		}
		f(arr1, 0, len - 1);
		bool test = true;
		for (int p = 0; p < len; p++) {
			if (arr1[p] != brr1[p]) {
				b << "test failed!";
				test = false;
				break;
			}

		}
		if (test == true) {
			b << "test succeed!";
		}

	}
}
void swapping(int& a, int& b) {     //swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void display(int* array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
void merge(int* array, int l, int m, int r) {
	int i, j, k, nl, nr;
	//size of left and right sub-arrays
	nl = m - l + 1; nr = r - m;
	int* larr = new int[nl];
	int* rarr = new int[nr];
	//fill left and right sub-arrays
	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];
	i = 0; j = 0; k = l;
	//marge temp arrays to real array
	while (i < nl && j < nr) {
		if (larr[i] <= rarr[j]) {
			array[k] = larr[i];
			i++;
		}
		else {
			array[k] = rarr[j];
			j++;
		}
		k++;
	}
	while (i < nl) {       //extra element in left array
		array[k] = larr[i];
		i++; k++;
	}
	while (j < nr) {     //extra element in right array
		array[k] = rarr[j];
		j++; k++;
	}
}
void mergeSort(int* array, int l, int r) {
	int m;
	if (l < r) {
		int m = l + (r - l) / 2;
		// Sort first and second arrays
		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);
		merge(array, l, m, r);
	}
}
int main() {
	ifstream a;
	a.open("test_case.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(mergeSort, a, b);
	system("pause");
	return 0;

}