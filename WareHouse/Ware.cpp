#include "Header.h"
class Ware{
    private:
    string name;
    int count=0;
    int index=0;
    public:
    inline string& getName()
    {
        return name;
    }
    inline int& getCount()
    {
        return count;
    }
    inline int& getIndex()
    {
        return index;
    }
    Ware(string name,int count,int index):name(name),count(count),index(index){}
    Ware()=default;
    
};