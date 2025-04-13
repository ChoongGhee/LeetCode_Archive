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
    int cnt = 0;
    int val = 0;

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return val;

        if(root->left) kthSmallest(root->left, k);

        cnt++;
        if(cnt == k) val = root->val;

        if(root->right) kthSmallest(root->right, k);

        return val;
        
    }
};