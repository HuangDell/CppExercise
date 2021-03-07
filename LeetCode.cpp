#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool binSearch(int num[],int index,int target)
    {
        if(target<num[index/2])
        binSearch(num,index/2,target);
        else if(target>num[index/2])
        binSearch(num+index/2,index/2,target);
        else if(target==num[index/2])
        return true;
        else return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num[matrix.size()*matrix[0].size()];
        int index=0;
        for (int i=0;i<matrix.size();i++)
            for (int j=0;j<matrix[0].size();j++)
                num[index++]=matrix[i][j];
        return binSearch(num,index,target);
    }
};
int main(void)
{
    vector <int> nums{1,2,1};
    Solution s=Solution();
}