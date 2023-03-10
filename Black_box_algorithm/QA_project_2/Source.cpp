#include<fstream>
using namespace std;
void test_driver(int(*func)(int), std::ifstream& a, std::ofstream& b) {
	int y, result;
	while (!a.eof()) {
		a >> y >> result;
		if (func(y) == result) {
			b << "Test succeed!\n";
		}
		else {
			b << "Test failed!\n";
		}
	}
}
int fact(int x) {
	if (x == 0) {
		return 1;
	}
	else {
		return fact(x - 1) * x;
	}
}
int degree(int n) {
	return n * n;
}
int main() {
	ifstream a("testcases1.txt");
	ofstream b("log1.txt");
	test_driver(fact, a, b);
	a.close();
	b.close();
	system("pause");
	return 0;
}