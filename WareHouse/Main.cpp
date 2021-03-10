#include "CreateUser.cpp"
#include "WareHouse.cpp"
int main(void)
{
    CreateUser cu=CreateUser();
    while(!cu.login());
    WareHouse wh;
    while(true)
    {
        wh.showList();
        wh.function();
    }
}