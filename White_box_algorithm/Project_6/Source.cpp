#include<iostream>
#include<fstream>
using namespace std;




int primeFactors(int n, ofstream& c, ofstream& b)
{
    int count = 0;
    c << "start" << endl;
    while (n % 2 == 0)
    {
        //cout << 2 << " ";
        n = n / 2;
        count++;
        c << "1-y exav" << endl;

    }

     
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        c << "2-y katarvec" << endl;
        while (n % i == 0)
        {
            //cout << i << " ";
            n = n / i;
            count++;

        }
    }

    
    if (n > 2)
    {
        count++;
        cout << count << "\n\n";
        c << "if-y gwrcum e" << endl;
    }
    return count;
}




void test_driver(int(*func)(int, ofstream&, ofstream&), std::ifstream& a, std::ofstream& c, std::ofstream& b)
{

    while (!a.eof()) {
        int x;
        int result;
        a >> x;
        a >> result;
        if (func(x, c, b) == result)
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
    test_driver(primeFactors, ifstr, ofstr, ofstr1);
    return 0;

}


//int factorial(int x)