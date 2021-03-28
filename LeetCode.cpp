#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int an=0;
        list <int>lis{0};
        bool check=false;
        for (auto num :height)
        {
            if(!check)
            {
                if (num > lis.back())
                    check = true;
                lis.push_back(num);
            }
            else
            {
                if (num <= lis.back())
                {
                    int more=0,size=lis.size();
                    auto head=lis.cbegin();
                    auto tale=lis.cend();
                    head++;
                    tale--;
                    while(head!=tale)
                    {
                        more+=*head;
                        head++;
                    }
                    an+=(lis.front()>lis.back()?lis.back():lis.front())*(size-2)-more;
                    check=false;
                    for (int i=0;i<size-1;i++)
                        lis.pop_front();
                }
                    lis.push_back(num);
            }
        }
        return an;
    }
};
int main(void)
{

    Solution s=Solution();
    vector<int> ve={4,2,0,3,2,5};
    cout<<s.trap(ve);
}