#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void dfs(string s ,vector<string> &dict,bool & is)
    {
        int size=s.size();
        if(size==0)
            is=true;
        for(int i=1;i<=size;i++)
        {
            string sub = s.substr(0, i);
            for (auto temp : dict)
                if (sub == temp)
                    dfs(s.substr(i),dict,is);
            if(is==true)
                return ;
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        bool is=false;
        dfs(s,wordDict,is);
        return is;
    }
};

int main(void)
{
    Solution s=Solution();
    vector<string> dict{"apple", "pen"};
    cout <<s.wordBreak("applepenapple",dict);
}