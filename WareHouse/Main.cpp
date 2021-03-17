/************************************************* 
Copyright:HuangDell 
Author: HuangDell
Date:2021/3/19
Description:Simple ware house control 
**************************************************/   
#include "CreateUser.cpp"
#include "WareHouse.cpp"
int main(void)
{
    system("mode con: cols=93 lines=34");//设置程序边框的大小
    system("color F0");//设置程序的背景色和前景色
    CreateUser cu=CreateUser();//用户登录
    while(!cu.login());
    WareHouse wh=WareHouse();
    while(true)//主程序部分
    {
        wh.showList();//输出货物列表
        wh.function();//仓库可执行的操作
        wh.saveData();//保存仓库数据
    }
}