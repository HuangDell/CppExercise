#include "Header.h"
#include "Ware.cpp"
#include <vector>
#include <sstream>
class WareHouse{
    private:
    const string BLACK=" ";
    const string TAB="\t\t";
    vector <Ware> house;
    ofstream os;
    ifstream is;

    void addWare(string name,int count)
    {
        Ware ware(name,count,house.size()+1);
        house.push_back(ware);
        os<<ware.getName()<<BLACK<<ware.getCount()<<BLACK<<ware.getIndex()<<endl;
    }
    public:
    WareHouse()
    {
        string temp;
        istringstream in;
        Ware ware;
        is.open("./bin/WareHouse.whm",ifstream::in);
        os.open("./bin/WareHouse.whm",ofstream::out |ofstream::app);
        while(getline(is,temp))
        {
            in=istringstream(temp);
            ware=Ware();
            in >>ware.getName()>>ware.getCount()>>ware.getIndex();
            house.push_back(ware);
        }
    }

    void showList()
    {
        system("cls");
        cout << "Your WareHouse's things list:";
        for (Ware ware:house)
            cout<<ware.getIndex()<<"."<<ware.getName()<<TAB<<ware.getCount()<<endl;
        if(house.empty())
        cout<< "Your warehouse is empty!"<<endl;
    }

    void function()
    {
        string input;
        cout<<"You can input A)To add a ware"<<TAB<<"B)To delete a ware"<<endl;
        cout<<"              C)To change a ware's status"<<endl;
        while(true)
        {
            cin>> input;
            if(input=="A")
            {
                string name;
                int count;
                cout<<"Please input the ware's name: ";
                cin >> name;
                cout<<endl<<"Please input the ware's amounts: ";
                while(!(cin >>count))
                {
                    cout<<"Please try again";
                }
                addWare(name,count);
                cout<<"Add a new ware finished!"<<endl;
                system("pause");
                showList();//此处可以优化
            }
            else if (input=="B")
            {
                int index;
            }
            else if(input =="C")
            {

            }

        }
    }
};