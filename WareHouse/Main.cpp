#include "CreateUser.cpp"
#include "WareHouse.cpp"
int main(void)
{
    system("mode con: cols=93 lines=34");
    CreateUser cu=CreateUser();
    while(!cu.login());
    WareHouse wh=WareHouse();
    while(true)
    {
        wh.showList();
        wh.function();
        wh.saveData();
    }
}