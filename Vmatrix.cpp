#include <iostream>
#include <utility>
using namespace std;
pair<int,int> bezout(int m, int n)
{
    if(n==0)
    return make_pair(1,0);
    auto deep=bezout(n,m%n);
    pair<int,int> an(deep.second,deep.first-m/n*deep.second);
    return an;
}
int main(void)
{
    auto an=bezout(8,3);
    cout<<an.first<<" "<<an.second;
}