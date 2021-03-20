#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        if (n==1)
            return k;
        return numWays(n-1,k)*(k-1)+numWays(n-1,k);
    }
};
int main(void)
{
    Solution s;
    cout <<s.numWays(3,2);
    

}