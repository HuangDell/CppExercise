#include "Header.h"
class Ware{
    private:
    string name;
    int count=0;
    public:
    inline string& getName()
    {
        return name;
    }
    inline int& getCount()
    {
        return count;
    }
    Ware(string name,int count):name(name),count(count){}
    Ware()=default;
    
};