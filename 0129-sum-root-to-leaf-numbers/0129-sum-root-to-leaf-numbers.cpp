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
    int dep = 0;
    int temp = 0;
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        if(dep == 0) temp += root->val;
        else temp = temp*10+root->val;

        // cout << dep << " "<< temp << " " << sum << endl;
        dep++;

        if(root->left) sumNumbers(root->left);
        if(root->right)sumNumbers(root->right);

        if(!root->right && !root->left) {
            sum += temp;
        }
        
        dep--;
        if(!dep) return sum;
        
        temp -= root->val;
        temp /= 10;
        // cout << dep << " "<< temp << " " << sum << endl;

        return 0;
    }
};