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
    ofstream os;
    ifstream is;

    void modeA()
    {
        string name;
        int count;
        cout << "Please input the ware's name: ";
        cin >> name;
        cout << endl
             << "Please input the ware's amounts: ";
        while (!(cin >> count))
        {
            cout << "Please try again";
        }
        addWare(name, count);
        cout << "Add a new ware sucessfully!" << endl;
        system("pause");
    }

    void modeB()
    {
        int index;
        string ware_detail;
        string temp;
        is.open("../data/WareHouse.whm", ifstream::in);
        cout << "Please input the ware's index that you what to delete:";
        while (!(cin >> index) || index - 1 > house.size())
            cout << "Please try again:";
        while (getline(is, temp))
        {
            string name;
            istringstream is_string(temp);
            is_string >> name;
            if (name != house[index - 1].getName())
                ware_detail += (temp + "\n");
        }
        is.close();
        os.open("../data/WareHouse.whm", ofstream::out);
        os << ware_detail;
        os.close();
        house.erase(house.begin() + index - 1);
    }

    void modeC()
    {
        int index;
        string choose;
        cout << "Please input the ware's index that you what to delete:";
        while (!(cin >> index))
            cout << "Please try again:";
        cout << house[index - 1].getName() << BLACK << house[index - 1].getCount() << BLACK << endl;
        cout << "A)Change the ware's name" << TAB << "B)Change the ware's amount";
        while (true)
        {
            if (choose == "A")
            {
                string name;
                cout << "Please input the new name";
                cin >> name;
                house[index - 1].getName() = name;
            }
            else if (choose == "B")
            {
                int amount;
                cout << "Please input the new amount";
                cin >> amount;
                house[index - 1].getCount() = amount;
            }
            else
                cout << "Please try again:";
        }
    }

    void addWare(string name, int count)
    {
        os.open("../data/WareHouse.whm", ofstream::out | ofstream::app);
        Ware ware(name, count);
        house.push_back(ware);
        os << ware.getName() << BLACK << ware.getCount() << BLACK << endl;
        os.close();
    }

public:
    WareHouse()
    {
        string temp;
        istringstream in;
        Ware ware;
        is.open("../data/WareHouse.whm", ifstream::in);
        while (getline(is, temp))
        {
            in = istringstream(temp);
            ware = Ware();
            in >> ware.getName() >> ware.getCount();
            house.push_back(ware);
        }
        is.close();
    }

    void showList()
    {
        system("cls");
        cout << "Your WareHouse's things list:" << endl;
        int index = 1;
        for (Ware ware : house)
            cout << index++ << "." << ware.getName() << TAB << ware.getCount() << endl;
        if (house.empty())
            cout << "Your warehouse is empty!" << endl;
    }

    void function()
    {
        string input;
        cout << "You can input A)To add a ware" << TAB << "B)To delete a ware" << endl;
        cout << "              C)To change a ware's status" << endl;
        cin >> input;
        if (input == "A")
            modeA();
        else if (input == "B")
            modeB();
        else if (input == "C")
            modeC();
    }
};