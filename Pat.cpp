#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class ch{
    public:
    int add;
    int next;
    ch(){}
    ch(int a,int n=0):add(a),next(n){}
};
void findNext(vector<ch> &head,const vector<ch>& temp,int n)
{
    for (int i=0;i<temp.size();i++)
    {
        if(temp[i].add==n)
        {
            head.push_back(temp[i]);
            if (head.back().next != -1)
                findNext(head, temp, head.back().next);
            break;
        }
    }
}

int main(void)
{
    int h1,h2,count;
    char ws;
    int isE=true;
    cin>>h1>>h2>>count;
    vector<ch> head1;
    vector<ch> head2;
    vector<ch> temp;
    head1.push_back(ch(h1));
    head2.push_back(ch(h2));
    for (int i=0;i<count;i++)
    {
        cin >>h1>>ws>>h2;
        if(h1==head1[0].add)
            head1[0].next=h2;
        if(h1==head2[0].add)
            head2[0].next=h2;
        temp.push_back(ch(h1,h2));
    }
    findNext(head1,temp,head1[0].next);
    findNext(head2,temp,head2[0].next);
    for(int i=0;i<head1.size();i++)
    {
        for (int j=0;j<head2.size();j++)
        {
            if(head1[i].add==head2[j].add && head1.size()-i==head2.size()-j)
            {
                printf("%d\n",head1[i].add);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
