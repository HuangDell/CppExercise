#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
public:
    vector<int> an;
    void getList(vector<vector <int>>& ve,vector<int>&num,int floors,int *hash)
    {
        if(floors==num.size()+1)
        {
            ve.push_back(an);
            return ;
        }
        int size=num.size();
        for (int i=0;i<size;i++)
        {
            if(hash[i]==0)
            {
                hash[i]=1;
                an.push_back(num[i]);
                getList(ve,num,floors+1,hash);
                hash[i]=0;
                an.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int hash[nums.size()];
        memset(hash,0,sizeof(int)*nums.size());
        vector<vector<int>> ve;
        getList(ve,nums,1,hash);
        return ve;
        
    }
};

int main(void)
{
    vector <int> nums{1,2,1};
    Solution s=Solution();
}