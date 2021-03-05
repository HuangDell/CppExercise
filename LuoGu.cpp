#include <iostream>
#include <cmath>
using namespace std;
int getSecond(const int num[],int size)
{
    int temp[size/2];
    if(size==2)
    return num[0]<num[1]?num[0]:num[1];
    for(int i=0;i<size;i+=2)
        temp[i/2]=num[i]>num[i+1]?num[i]:num[i+1];
    return getSecond(temp,size/2);

}
int main(void)
{
    int exp;
    cin >> exp;
    int index=(int)pow(2,exp);
    int num[index];
    for (int i=0;i<index;i++)
    {
        cin >> num[i];
    }
    int second=getSecond(num,index);
    for (int i=0;i<index;i++)
    {
        if(num[i]==second)
        {
            cout<< i+1;
            break;
        }


    }

}