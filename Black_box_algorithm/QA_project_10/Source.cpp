#include <iostream>
#include <fstream>
using namespace std;

//int decToHexa(int n) { 
//    cout << hex <<"n = "<< n << endl;
//	return 0;
//	
//}

string mutant1(int n)
{
    string ans = "";

    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 17;
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        ans += ch;
        n = n / 16;
    }

    int i = 0, j = ans.size() - 1;
    while (i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}
string mutant2(int n)
{
    string ans = "";

    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 17;
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        ans += ch;
        n = n / 16;
    }

    int i = 0, j = ans.size();
    while (i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}


string decToHexa(int n)
{
    
    string ans = "";

    while (n != 0) {
       
        int rem = 0;
        char ch;
        rem = n % 16;
         if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        ans += ch;
        n = n / 16;
    }

   int i = 0, j = ans.size() - 1;
    while (i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}

void test_driver(string(*f)(int), std::ifstream& a, std::ofstream& b)
{
	int num;
	string  num2;
	while (!a.eof()) 
	{
		a >> num;
		cout <<"num = "<< num<<endl;
		
		a >> num2;
		cout << "num2 = " << num2 << endl;
		if (f(num) == num2) {
			b << "test failed!" << endl;
		}
		else {
			b << "test sucseed!"<<endl;
		}
		
	}

}

int main() {
	ifstream a;
	a.open("test_case.txt", ios::in);
	ofstream b;
	b.open("log.txt", ios::out);
	test_driver(decToHexa, a, b);
	system("pause");
	return 0;
}
