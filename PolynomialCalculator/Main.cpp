#include <string>
#include <iostream>
#include <vector>
#include "Judge.cpp"
#include "Polynomial.cpp"
using namespace std;
int main(void)//main函数启动程序，实现交互。
{
    string input,choose;
    vector<double> poly;
    Judge judge;
    while(true)
    {
        cin>>input;
        poly = judge.polynomial(input);
        if(!poly.empty())
        {
            Polynomial polynomial(poly,judge.getName());
            cout << polynomial.to_string();
        }
    }

}

