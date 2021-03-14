#include "Header.h"
class Ware{
    private:
    string name;
    int count=0;
    string date;
    public:
    inline string& getName()
    {
        return name;
    }
    inline int& getCount()
    {
        return count;
    }
    inline string& getDate()
    {
        return date;
    }
    Ware(string name,int count,string date):name(name),count(count),date(date){}
    Ware()=default;
    
};