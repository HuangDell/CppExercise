#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
bool isInH(const string &s)
{
    auto head = s.begin();
    auto tale = s.end() - 1;
    while (head != tale)
    {
        if ((*head != '0' && *head != '1') || (*tale != '0') && (*tale != '1') || *head != *tale)
            return false;
        head++;
        tale--;
    }
    return true;
}
void genElements(int n, queue<string> &ve)
{
    if (n == 1)
        return;
    int index = ve.size();
    string temp;
    for (int i = 0; i < index; i++)
    {
        temp = ve.front();
        temp = "0" + temp + "0";
        ve.push(temp);
        temp = ve.front();
        temp = "1" + temp + "1";
        ve.push(temp);
        ve.pop();
    }
    genElements(n - 1, ve);
}

int main(void)
{
    int count;
    queue<string> ve;
    ve.push("0");
    ve.push("1");
    cin >> count;
    genElements(count, ve);
    int size = ve.size();
    string st[ve.size()];
    for (int i = 0; !ve.empty(); i++)
    {
        st[i] = ve.front();
        ve.pop();
    }
    sort(st, st + size);
    for (string s : st)
    {
        cout << isInH(s) << endl;
    }
}