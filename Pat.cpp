#include <iostream>
#include <string>
using namespace std;
class p{
    public:
    int id;
    string name;
    int age;
    p(){}
    p(int id,string name,int age):id(id),name(name),age(age){}
};
inline bool com(p t,p x,int col)
{
    if(col==1)
        return t.id>x.id;
    else if(col==2)
    {
        if(t.name>x.name)
            return true;
        else if(t.name<x.name)
            return false;
        else return t.id>x.id;
    }
    else if(col==3)
    {
        if(t.age>x.age)
            return true;
        else if(t.age<x.age)
            return false;
        else return t.id>x.id;
    }
    return true;
}



void sort(p*t,int size,int col)
{
    int i,j;
    if(col==1)
    {
        for (i=1;i<size;i++)
        {
            auto temp=t[i];
            for (j=i-1;j>=0 && com(t[j],temp,col);j--)
                t[j+1]=t[j];
            t[j+1]=temp;
        }
    }
    else if(col==2)
    {
        for (i=1;i<size;i++)
        {
            auto temp=t[i];
            for (j=i-1;j>=0 && com(t[j],temp,col);j--)
                t[j+1]=t[j];
            t[j+1]=temp;
        }
    }
    else if(col==3)
    {
        for (i=1;i<size;i++)
        {
            auto temp=t[i];
            for (j=i-1;j>=0 && com(t[j],temp,col);j--)
                t[j+1]=t[j];
            t[j+1]=temp;
        }
    }

}
int main(void)
{
    int count,col;
    cin>> count>>col;
    p t[count];
    for(int i=0;i<count;i++)
    {
        int id,age;
        string name;
        cin >>id>>name>>age;
        t[i]=p(id,name,age);
    }
    sort(t,count,col);
    for(int i=0;i<count;i++)
    {
        printf("%06d %s %d\n",t[i].id,t[i].name.c_str(),t[i].age);
    }
}
