#include <string>
#include <conio.h>
#include <cctype>
void printMenu()
{
    printf("1.���Ӷ���ʽ\t\t2.�鿴����ʽ\t\t3.�ӷ�����\n");
    printf("4.��������\t\t  5.�˷�����\t\t  6.��ֵ\n");

}

bool isLegal(string choose)
{
    if(!isdigit(choose[0]) && choose.size()>1)
        return false;
    return true;




}

void Mode1()
{
    string input;
    vector<double> poly;
    Judge judge;
    mode1:
    system("cls");
    printf("������һ������ʽ(��ʽ:����(��ѡ)=(ϵ��,ָ��)\n");
    cin >> input;
    poly = judge.polynomial(input);
    if (!poly.empty())
    {
        Polynomial polynomial(poly, judge.getName());
        printf("������Ķ���ʽ�ǣ�%s=",judge.getName().c_str());
        cout << polynomial.to_string()<<endl;
        printf("�������������\n");
        getch();
    }
    else
        goto mode1;
    
    
}