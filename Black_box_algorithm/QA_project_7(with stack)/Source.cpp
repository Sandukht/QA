#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
void test_driver(void(*f)(stack<int>&), std::ifstream& a, std::ofstream& b) {
	while (!a.eof()) {
		int len;

		a >> len;

		stack<int> arr;
		int x;
		for (int k = 0; k < len; k++) {
			a >> x;
			arr.push(x);
		}
		stack<int> brr;
		for (int l = 0; l < len; l++) {
			a >> x;
			brr.push(x);
		}
		stack <int> result;
		for (size_t i = 0; i < arr.size(); i++)
		{
			cout << arr.top() << endl;
			arr.pop();
		}
		f(arr);

		if (arr == brr) b << "test succeed!:)\n";
		else {
			b << "test faild!:(\n";
		}
		for (size_t i = 0; i < arr.size(); i++)
		{
			cout << arr.top() << endl;
			arr.pop();
		}

	}
}
void stack_sort(stack<int>& input)
{
	stack<int> tmpStack;

	while (!input.empty())
	{

		int tmp = input.top();
		input.pop();
		while (!tmpStack.empty() && tmpStack.top() > tmp)
		{

			input.push(tmpStack.top());
			tmpStack.pop();
		}


		tmpStack.push(tmp);
	}


}

int main() {
	cout << 1232312;
	ifstream a;
	a.open("Test_case.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(stack_sort, a, b);
	system("pause");
	return 0;

}