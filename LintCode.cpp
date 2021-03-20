#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        bool dp[x+1]={false};
        if(x>=3 && x<7)
        {
            dp[3] = true;
            for (int i=4;i<=x;i++)
            dp[i]=dp[i-3];
        }
        if(x>=7)
        {
            dp[7] = true;
            for (int i=8;i<=x;i++)
            dp[i]=dp[i-3] || dp[i-7];
        }

        return (dp[x]==true ?"Yes":"No");
    }
};
int main(void)
{
    Solution s;
    cout << s.isBuild(4);
    

}