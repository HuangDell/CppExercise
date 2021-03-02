#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution
  {
  public:
      vector<vector<int>> levelOrder(TreeNode *root)
      {
          vector<vector<int>> an;
          queue<TreeNode*> tip;
          vector<int> rootval;
          rootval.push_back(root->val);
          an.push_back(rootval);
          tip.push(root);
          while(true)
          {
              vector<int> num;
              TreeNode *cur = tip.front();
              if(cur->left!=nullptr)
              {
                  num.push_back(cur->left->val);
                  tip.push(cur->left);
              }
              if(cur->right!=nullptr)
              {
                  num.push_back(cur->right->val);
                  tip.push(cur->right);
              }
              tip.pop();
              an.push_back(num);
              if(tip.empty())
              
          }
          return an;
      }
  };
  Line 27: Char 23: runtime error: member access within misaligned address 0xbebebebebebebebe for type 'TreeNode', which requires 8 byte alignment (solution.cpp)
0xbebebebebebebebe: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:36:23