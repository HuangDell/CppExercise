#include <iostream>
using namespace std;
char *convertDecimalToHex(int);
void convertDecimalToHex(int,char*);
int main(void)
{
    int num,sum=0;
    char *s;
    std::cin>> num;
    cout<< convertDecimalToHex(num);
    convertDecimalToHex(num,s);
    cout<< s<<endl;
}
void convertDecimalToHex(int value, char *s)
{
    s=convertDecimalToHex(value);
}
char * convertDecimalToHex(int value)
{
    int mod=0,index=48;
    char hex[50]={0};
    while(value)
    {
        mod=value%16;
        switch (mod)
        {
            case 10:
            hex[index]='a';
            break;
            case 11:
            hex[index]='b';
            case 12:
            hex[index]='c';
            break;
            case 13:
            hex[index]='d';
            break;
            case 14:
            hex[index]='e';
            break;
            case 15:
            hex[index]='f';
            break;
            default:
            hex[index]='0'+mod;
            break;
        }
        value/=16;
        index--;
    }
    return hex+index+1;
}