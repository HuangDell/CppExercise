/************************************************* 
Copyright:HuangDell 
Author: HuangDell
Date: 2021/6/15
Description:Simple ware house control 
**************************************************/   
#include "Header.h"
#include <conio.h>
class CreateUser{//创建用户
    private:
    ofstream os;
    ifstream is;
    string USER_NAME;
    string USER_PASSWORD;
    bool hasCount=false;
    int amountWare = 0;
    
    bool createNew()//不存在就创建新的用户
    {
        os.open("../data/account.whm", ostream::out | ostream::app);
        string userName, userPassword;
        char ch;
        cout << "Please create a account to use the software" << endl;
        cout << "Please input the user name: ";
        cin >> userName;
        cout << "Please input the password: ";
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
                cout << '\b'<<'\b';
            userPassword += ch;
            cout << "*";
        }
        os << userName << endl
           << userPassword << endl
           << amountWare << endl;
        return true;
    }
    bool loadUser()//载入用户数据
    {
        cout << "Your account name:" << USER_NAME << endl
             << "Please input your password: ";
        char ch;
        string password;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
                cout << '\b'<<' '<<'\b'<<' '<<'\b';
            else
            password += ch;
            cout << "*";
        }
        if (password == USER_PASSWORD)
            return true;
        else
            return false;
    }

    public:
    CreateUser()//将用户数据载入到内存中
    {
        is.open("../data/account.whm",ifstream::in);
        if (is >> USER_NAME >> USER_PASSWORD>>amountWare)
            hasCount = true;
    }

    bool login()//登录
    {
        system("cls");
        if (hasCount == false)
            return createNew();
        else
            return loadUser();
    }
};