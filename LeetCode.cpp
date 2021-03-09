#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        auto head=S.begin();
        auto end=S.end();
        while(head!=end-1 && head!=end)
        {
            if(*head==*(head+1))
            {
                S.erase(head);
                S.erase(head);
                return removeDuplicates(S);
            }
            else 
            head++;
        }
        return S;
    }
};

int main(void)
{
    Solution s=Solution();
    cout << s.removeDuplicates("aaaaaaaa");

}