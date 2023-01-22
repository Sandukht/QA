#include<iostream>
#include<fstream>
using namespace std;

int isPower(int x, long int y, ofstream& c, ofstream& b)
{
    
    if (x == 1)
    {
        c << "x=1" << endl;
        return (y == 1);
    }
    
    long int pow = 1;
    while (pow < y) {
        c << "pow<y" << endl;
        pow *= x;
    }
    c<<"bbb"<<endl;
    return (pow == y);
}

void test_driver(int(*func)(int, long int, ofstream&, ofstream&), std::ifstream& a, std::ofstream& c, std::ofstream& b)
{

    while (!a.eof()) {
        int x, y, result;
        a >> x;
        a >> y;
        a >> result;
        if (func(x, y, c, b) == result)
        {
            b << "test succed!" << endl;
        }
        else {
            b << "test failed!" << endl;
        }

    }
}




int main()
{

    ifstream ifstr;
    ifstr.open("TC.txt", ios::in);
    ofstream ofstr, ofstr1;
    ofstr.open("Log.txt", ios::out);
    ofstr1.open("log1.txt", ios::out);
    test_driver(isPower, ifstr, ofstr, ofstr1);
    return 0;
    
}


//int factorial(int x)