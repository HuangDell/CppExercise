#include "Header.h"
#include "Ware.cpp"
#include <vector>
#include <sstream>
#include <windows.h>
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
        int account;
        SYSTEMTIME time;
        cout << "\t\tPlease input the ware's name: ";
        cin >> name;
        cout << "\t\tPlease input the ware's amounts: ";
        while (!(cin >> account))
            cout << "\t\tPlease try again";
        GetLocalTime(&time);
        string temp=to_string(time.wMinute);
        string data=to_string(time.wMonth)+"/"+to_string(time.wDay)+","+to_string(time.wHour)+":"+(temp.length()<2 ?"0"+temp:temp);
        Ware ware(name, account,data);
        house.push_back(ware);
        cout << "\t\tAdd a new ware sucessfully!";
        Sleep(1000);
    }

    void modeB()
    {
        int index;
        cout << "\t\tPlease input the ware's index that you what to delete:";
        while (!(cin >> index) || index - 1 > house.size())
            cout << "Please try again:";
        house.erase(house.begin() + index - 1);
    }

    void modeC()
    {
        int index;
        string choose;
        cout << "\t\tPlease input the ware's index that you what to change:";
        while (!(cin >> index))
            cout << "\t\tPlease try again:";
        drawLine(46);
        printf("\t\t|%04d  |%-15s|%-10d|%-10s|\n", index, house[index-1].getName().c_str(), house[index-1].getCount(), house[index-1].getDate().c_str());
        drawLine(46);

        cout << "\t\tA)Change the ware's name" << TAB << "B)Change the ware's amount\n";
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
            else
                cout << "\t\tPlease try again:";
        }
    }

    void modeD()
    {

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
            in >> ware.getName() >> ware.getCount() >> ware.getDate();
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
            drawLine(46);
            printf("\t\t|%-6s|%-15s|%-10s|%-10s|\n", "Index", "Name", "Amount", "Date");
            for (Ware ware : house)
            {
                drawLine(46);
                printf("\t\t|%04d  |%-15s|%-10d|%-10s|\n", index, ware.getName().c_str(), ware.getCount(), ware.getDate().c_str());
                index++;
            }
            drawLine(46);
        }
        else
            printf("Sorry you list is empty\n");
    }

    void function()
    {
        string input;
        cout << "\t\tA)To add a ware" << TAB << "B)To delete a ware" << endl;
        cout << "\t\tC)To change a ware's status" << endl;
        printf("\t\t");
        cin >> input;
        if (input == "A")
            modeA();
        else if (input == "B")
            modeB();
        else if (input == "C")
            modeC();
    }

    void saveData()
    {
        ofstream os("../data/WareHouse.whm",ofstream::out);
        for (Ware ware : house)
            os << ware.getName() << BLACK << ware.getCount() << BLACK << ware.getDate() << endl;
        os.close();
    }
};