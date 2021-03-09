#include "Header.h"
#include <conio.h>
class CreateUser{
    private:
    string USER_NAME;
    string USER_PASSWORD;
    bool hasCount=false;
    public:
    ofstream os;
    ifstream is;
    CreateUser()
    {
        is.open("./data/account.whf",ifstream::in);
        os.open("./data/account.whf",ostream::out);
        if(is >> USER_NAME>> USER_PASSWORD)
        hasCount=true;
    }
    inline bool getStatus()
    {
        return hasCount;
    }
    void login()
    {
        if(hasCount==false)
        {
            string userName,userPassword;
            char ch;
            cout<<"Please create a account to use the software"<<endl;
            cout<< "Please input the user name: ";
            cin >> userName;
            cout <<endl<<"Please input the password: ";
            while((ch=_getch())!='\r')
            {
                userPassword+=ch;
                cout <<"*";
            }
            os<<userName<<userPassword;
        }
        else
        {
            cout<<"Your account name:"<<USER_NAME<<endl<<"Please input your password: ";
            char ch;
            string password;
            while((ch=_getch())!='\n')
            {
                password+=ch;
                cout <<"*";
            }
            if(password==USER_PASSWORD)
            {
                cout <<"Welcome!";
            }
        }
    }
};