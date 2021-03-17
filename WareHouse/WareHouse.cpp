/************************************************* 
Copyright:HuangDell 
Author: HuangDell
Date:2021/3/19
Description:Simple ware house control 
**************************************************/   
#include "Header.h"
#include "Ware.cpp"
#include <vector>
#include <sstream>
#include <windows.h>
#define LINE_LENGTH 57
class WareHouse
{
private:
    const string BLACK = " ";
    const string TAB = "\t\t";
    vector<Ware> house;
    inline void drawLine(int length) //绘画表格
    {
        printf("\t\t");
        for (int i=0;i<length;i++)
            printf("-");
        puts("");
    }
    int findWare(string name)//查询货物，返回货物的index
    {
        int index=0;
        for (auto ware:house)
        {
            if(ware.getName()==name)
            return index;
            index++;
        }
        return -1;
    }
    inline void printWare(int index)//输出货物
    {
        drawLine(LINE_LENGTH);
        printf("\t\t|%04d  |%-15s|%-10d|%-10.2f|%-10s|\n", index+1, house[index].getName().c_str(), house[index].getCount(),house[index].getPrice() ,house[index].getDate().c_str());
        drawLine(LINE_LENGTH);
    }
    void modeA()//添加货物
    {
        string name;
        int account,price;
        SYSTEMTIME time;
        cout << "\t\tPlease input the ware's name: ";
        cin >> name;
        int index=findWare(name);
        if(index==-1)
        {
            cout << "\t\tPlease input the ware's amounts: ";
            while (!(cin >> account))
                cout << "\t\tPlease try again:";
            cout << "\t\tPlease input the ware's price: ";
            while (!(cin >> price))
                cout << "\t\tPlease try again";
            GetLocalTime(&time);
            string temp = to_string(time.wMinute);
            //设置入库时间
            string data = to_string(time.wMonth) + "/" + to_string(time.wDay) + "," + to_string(time.wHour) + ":" + (temp.length() < 2 ? "0" + temp : temp);
            Ware ware(name, account, price, data);
            house.push_back(ware);
            cout << "\t\tAdd a new ware successfully!";
        }
        else
        {
            printWare(index);
            printf("\t\tPlease input the extral amounts: ");
            while (!(cin >> account))
                cout << "\t\tPlease try again:";
            house[index].getCount()+=account;
            printf("\t\tAdd ware successfully!");
        }
        Sleep(1000);
    }

    void modeB()//货物出库
    {
        int index;
        string name;
        cout << "\t\tPlease input the ware's name:";
        cin >> name;
        index=findWare(name);
        if(index!=-1)
        {
            int amount;
            printWare(index);
            Again:
            printf("\t\tPlease input the amount of sell:");
            cin >> amount;
            if(amount <0 || amount > house[index].getCount())
            {
                printf("\t\tNumber Invalid!");
                goto Again;
            }
            house[index].getCount()-=amount;
            printf("\t\tSell successfuly!");
            Sleep(1000);
        }
        else
        {
            printf("\t\tSorry can't find the \"%s\"",name.c_str());
            Sleep(2000);
        }
        if(house[index].getCount()==0)
        house.erase(house.begin()+index);//货物数量为0时从仓库中移除
        return ;
    }

    void modeC()//提供修改货物属性的方法
    {
        string name;
        string choose;
        cout << "\t\tPlease input the ware's name:";
        cin >> name;
        int index = findWare(name);
        if (index != -1)
        {
            printWare(index);
            cout << "\t\tA)Change the name" << TAB << "B)Change the amount\n";
            printf("\t\tC)Change the price");
            printf("\t\t");
            cin >> choose;
            while (true)
            {
                if (choose == "A")
                {
                    string name;
                    cout << "\t\tPlease input the new name:";
                    cin >> name;
                    house[index - 1].getName() = name;
                    printf("\t\tChange the ware's name successfully!");
                    Sleep(1000);
                    break;
                }
                else if (choose == "B")
                {
                    int amount;
                    cout << "\t\tPlease input the new amount:";
                    cin >> amount;
                    house[index - 1].getCount() = amount;
                    printf("\t\tChange the ware's amount successfully!");
                    Sleep(1000);
                    break;
                }
                else if (choose == "C")
                {
                    int price;
                    printf("\t\tPlease input the new price");
                    scanf("%d", price);
                    house[index - 1].getPrice() = price;
                    printf("\t\tChange the ware's price successfully!");
                    Sleep(1000);
                    break;
                }
                else
                    cout << "\t\tPlease try again:";
            }
        }
        else
        {
            printf("\t\tSorry can't find the \"%s\"",name.c_str());
            Sleep(2000);
        }
        return ;
            
    }

    void modeD()//提供查询货物的方法
    {
        string name;
        printf("\t\tPlease input the name:");
        cin >> name;
        int index=findWare(name);
        if(index==-1)
        {
            printf("\t\tSorry the \"%s\" is not in the warehouse\n", name.c_str());
            printf("\t\t");
            Sleep(2000);
            return;
        }
        else
        {
         
            printWare(index);
            printf("\t\tPress anything to exit\n\t\t");
            _getch();
        }
    }
public:
    WareHouse()//构造函数，用于读取数据库中的数据并载入到内存中
    {
        string temp;
        ifstream is("../data/WareHouse.whm", ifstream::in);
        istringstream in;
        Ware ware;
        while (getline(is, temp))
        {
            in = istringstream(temp);
            ware = Ware();
            in >> ware.getName() >> ware.getCount() >>ware.getPrice()>> ware.getDate();
            house.push_back(ware);
        }
        is.close();
    }

    void showList()//输出仓库中所有货物的信息
    {
        system("cls");
            printf("\t\t\t\t    WareHouse  List\n");
        if (!house.empty())
        {
            int index = 1;
            drawLine(LINE_LENGTH);
            printf("\t\t|%-6s|%-15s|%-10s|%-10s|%-10s|\n", "Index", "Name", "Amount","Price","Date");
            for (Ware ware : house)
            {
                drawLine(LINE_LENGTH);
                printf("\t\t|%04d  |%-15s|%-10d|%-10.2f|%-10s|\n",index,ware.getName().c_str(), ware.getCount(),ware.getPrice(),ware.getDate().c_str());
                index++;
            }
            drawLine(LINE_LENGTH);
        }
    }

    void function()//提供操作列表
    {
        string input;
        cout << "\t\tA)Purchase" << TAB << "\t\t\tB)Sell" << endl;
        cout << "\t\tC)Modify" << TAB <<"\t\t\tD)Query"<<endl;
        printf("\t\t");
        cin >> input;
        if (input == "A")
            modeA();
        else if (input == "B")
            modeB();
        else if (input == "C")
            modeC();
        else if (input == "D")
            modeD();
            
    }

    void saveData()//保存数据
    {
        ofstream os("../data/WareHouse.whm",ofstream::out);
        for (Ware ware : house)
            os << ware.getName() << BLACK << ware.getCount() << BLACK << ware.getPrice() << BLACK << ware.getDate() << endl;
        os.close();
    }
};