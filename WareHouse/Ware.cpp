#include "Header.h"
class Ware{
    private:
    string name;
    int count=0;
    string date;
    double price;
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
    inline double& getPrice()
    {
        return price;
    }
    Ware(string name,int count,int price,string date):name(name),count(count),price(price),date(date){}
    Ware()=default;
};