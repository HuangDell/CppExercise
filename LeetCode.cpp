#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
class Solution {
    bool isInDict(string s,const vector<string> &dict)
    {
        for (auto temp:dict)
            if(s==temp)
            return true;
        return false;
    }
public:

    bool wordBreak(string s, vector<string> &wordDict)
    {
        int size=s.size();
        bool dp[size+1];
        memset(dp,false,sizeof(bool)*(size+1));
        dp[0]=true;
        for(int i=1;i<=size;i++)
            for (int j=0;j<i && !dp[i];j++)
                dp[i] = dp[j] && isInDict(s.substr(j, i - j), wordDict);
        return dp[size];
    }
};
int main(void)
{
    Solution s=Solution();
    vector<string> dict{"apple", "pen"};
    cout <<s.wordBreak("applepenapple",dict);
}