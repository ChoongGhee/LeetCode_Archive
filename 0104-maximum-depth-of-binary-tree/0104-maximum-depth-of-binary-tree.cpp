/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(!root) return 0;
            return dfs(root, 1);
        }

        int dfs(TreeNode* cur, int height){
            if(!cur->left && !cur->right) return height;

            int l_h = cur->left ? dfs(cur->left, height+1) : 0;
            int r_h = cur->right ? dfs(cur->right, height+1) : 0;

            return l_h > r_h ? l_h : r_h;
        }
    };