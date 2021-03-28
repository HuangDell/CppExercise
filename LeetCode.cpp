#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
class Solution {
public:
    void findIsland(vector<vector<char>>& grid,int i,int j)
    {
        if(grid[i][j]=='1')
        grid[i][j]='0';
        else
        return;
        if(j+1<grid[0].size())
        findIsland(grid,i,j+1);
        if(i+1<grid.size())
        findIsland(grid,i+1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;

        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                if(grid[i][j]=='1')
                {
                    count++;
                    findIsland(grid,i,j);
                }
        return count;
    }
};
int main(void)
{

    Solution s=Solution();
    vector <vector<char>> grid;
    grid.push_back(vector<char>{'1','1','1','1','0'});
    grid.push_back(vector<char>{'1','1','0','1','0'});
    grid.push_back(vector<char>{'1','1','0','0','0'});
    grid.push_back(vector<char>{'0','0','0','0','0'});



    cout<<s.numIslands(grid);
}