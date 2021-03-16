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
    inline void drawLine(int length) 
    {
        printf("\t\t");
        for (int i=0;i<length;i++)
            printf("-");
        puts("");
    }
    void modeA()
    {
        string name;
        int account,price;
        SYSTEMTIME time;
        cout << "\t\tPlease input the ware's name: ";
        cin >> name;
        cout << "\t\tPlease input the ware's amounts: ";
        while (!(cin >> account))
            cout << "\t\tPlease try again";
        cout << "\t\tPlease input the ware's price: ";
        while (!(cin >> price))
            cout << "\t\tPlease try again";
        GetLocalTime(&time);
        string temp=to_string(time.wMinute);
        string data=to_string(time.wMonth)+"/"+to_string(time.wDay)+","+to_string(time.wHour)+":"+(temp.length()<2 ?"0"+temp:temp);
        Ware ware(name, account,price,data);
        house.push_back(ware);
        cout << "\t\tAdd a new ware sucessfully!";
        Sleep(1000);
    }

    void modeB()
    {
        int index;
        cout << "\t\tPlease input the ware's index:";
        while (!(cin >> index) || index - 1 > house.size())
            cout << "Please try again:";
        house.erase(house.begin() + index - 1);
        printf("Delete the ware successfully!");
    }

    void modeC()
    {
        int index;
        string choose;
        cout << "\t\tPlease input the ware's index:";
        while (!(cin >> index))
            cout << "\t\tPlease try again:";
        drawLine(LINE_LENGTH);
        printf("\t\t|%04d  |%-15s|%-10d|%-10.2f|%-10s|\n", index, house[index-1].getName().c_str(), house[index-1].getCount(),house[index-1].getPrice() ,house[index-1].getDate().c_str());

        drawLine(LINE_LENGTH);

        cout << "\t\tA)Change the ware's name" << TAB << "B)Change the ware's amount\n";
        printf("\t\tC)Change the ware's price");
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
                printf("Change the ware's name successfully!");
                Sleep(1000);
                break;
            }
            else if (choose == "B")
            {
                int amount;
                cout << "\t\tPlease input the new amount:";
                cin >> amount;
                house[index - 1].getCount() = amount;
                printf("Change the ware's amount successfully!");
                Sleep(1000);
                break;
            }
            else if(choose =="C")
            {
                int price;
                printf("\t\tPlease input the new price");
                scanf("%d",price);
                house[index-1].getPrice()=price;
                printf("Change the ware's price successfully!");
                Sleep(1000);
                break;
            }
            else
                cout << "\t\tPlease try again:";
        }
    }

    void modeD(string name)
    {
        int index=1;
        for (auto ware:house)
        {
            if(ware.getName()==name)
            {
                drawLine(LINE_LENGTH);
                printf("\t\t|%04d  |%-15s|%-10d|%-10.2f|%-10s|\n",index,ware.getName().c_str(), ware.getCount(),ware.getPrice(),ware.getDate().c_str());
                drawLine(LINE_LENGTH);
                printf("\t\tPush any keys to exit\n\t\t");
                _getch();
                return;
            }
            index++;
        }
        printf("\t\tSorry the \"%s\" is not in the warehouse\n", name.c_str());
        printf("\t\tPush any keys to exit\n\t\t");
        _getch();
        return ;


    }
public:
    WareHouse()
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

    void showList()
    {
        system("cls");
            printf("\t\t\t\tWareHouse List\n");
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
        else
            printf("\t\t\t\tYou list is empty!\n");
    }

    void function()
    {
        string input;
        cout << "\t\tA)To add a ware" << TAB << "B)To delete a ware" << endl;
        cout << "\t\tC)To change a ware's status"
             << "\t"
             << "Name)To find a ware by name" << endl;
        printf("\t\t");
        cin >> input;
        if (input == "A")
            modeA();
        else if (input == "B")
            modeB();
        else if (input == "C")
            modeC();
        else
            modeD(input);
            
    }

    void saveData()
    {
        ofstream os("../data/WareHouse.whm",ofstream::out);
        for (Ware ware : house)
            os << ware.getName() << BLACK << ware.getCount() << BLACK << ware.getPrice() << BLACK << ware.getDate() << endl;
        os.close();
    }
};