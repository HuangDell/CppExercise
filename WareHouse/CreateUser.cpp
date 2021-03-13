#include "Header.h"
#include <conio.h>
class CreateUser{
    private:
    ofstream os;
    ifstream is;
    string USER_NAME;
    string USER_PASSWORD;
    bool hasCount=false;
    int amountWare = 0;
    
    bool createNew()
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
    bool loadUser()
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
    CreateUser()
    {
        is.open("../data/account.whm",ifstream::in);
        if (is >> USER_NAME >> USER_PASSWORD>>amountWare)
            hasCount = true;
    }

    bool login()
    {
        system("cls");
        if (hasCount == false)
            return createNew();
        else
            return loadUser();
    }
};