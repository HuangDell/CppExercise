#include <string>
#include <iostream>
#include <vector>
#include "Judge.cpp"
#include "Polynomial.cpp"
#include "Menu.cpp"
using namespace std;
int main(void)//main函数启动程序，实现交互。
{
    string choose;
    while(true)
    {
        start:
        system("cls");
        printMenu();
        cin>>choose;
        if(!isLegal(choose))
            goto start;
        switch(stoi(choose))
        {
            case 1:Mode1();
            break;
        }
    }
}

