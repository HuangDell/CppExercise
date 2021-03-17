/************************************************* 
Copyright:HuangDell 
Author: HuangDell
Date:2021/3/19
Description:Simple ware house control 
**************************************************/   
#include "Header.h"
class Ware{//使用类来定义货物的基本属性
    private:
    string name;
    int count=0;
    string date;
    double price;
    public:
    inline string& getName()//使用封装
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