#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size =nums.size();
        vector<int> ve;
        for (int i=0;i<size;i++)
        {
            int max=-1;
            for(int j=(i+1)%size;j!=i;j=(j+1)%size)
            {
                if(nums[j]>nums[i])
                {
                    max=nums[j];
                    break;
                }
            }
            ve.push_back(max);
        }
        return ve;
    }
};
int main(void)
{
    vector <int> nums{1,2,1};
    Solution s=Solution();
    for (auto num :s.nextGreaterElements(nums))
    cout << num;
}