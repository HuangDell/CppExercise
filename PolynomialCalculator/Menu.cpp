#include <string>
#include <conio.h>
#include <cctype>
#include "DataBase.cpp"
class Menu
{
    string input;
    Judge judge;
    DataBase data;
    
    public:
    void printMenu()
    {
        printf("1.添加多项式\t\t2.查看多项式\t\t3.加法计算\n");
        printf("4.减法计算\t\t  5.乘法计算\t\t  6.求值\n");
    }

    bool isLegal(string choose)
    {
        if (!isdigit(choose[0]) && choose.size() > 1)
            return false;
        return true;
    }

    void Mode1()
    {
        vector<double> poly;
        judge.clear();
        system("cls");
        printf("请输入一个多项式(格式:名称(可选)=(系数,指数))\n");
        mode1:
        cin >> input;
        poly = judge.polynomial(input);
        if (!poly.empty())
        {
            Polynomial polynomial(poly, judge.getName());
            data.addPoly(polynomial);
            printf("你输入的多项式是：%s=", judge.getName().c_str());
            cout << polynomial.to_string() << endl;
            printf("输入任意键继续\n");
            getch();
        }
        else
        {
            printf("输入格式有误，请重新输入！\n");
            goto mode1;
        }
    }
    void Mode2()
    {
        system("cls");
        auto data_poly=data.getData();
        printf("目前储存的多项式有：");
        for (auto temp:data_poly)
            printf("%s=%s\n",temp.getName().c_str(),temp.to_string().c_str());
        printf("输入任意键继续\n");
        getch();
    }
};