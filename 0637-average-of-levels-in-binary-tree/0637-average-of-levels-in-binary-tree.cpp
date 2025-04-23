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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        double sum = 0;
        int cur_lv = 0;
        int cnt = 0;

        while(!q.empty()){
            pair<TreeNode*, int> front = q.front();

            if( cur_lv != front.second ){
                result.push_back((double)sum/cnt);
                
                sum = 0;
                cnt = 0;
                cur_lv = front.second;
                
            }

            sum += front.first->val;
            cnt++;

            if(front.first->left) q.push(make_pair(front.first->left, front.second+1));
            if(front.first->right) q.push(make_pair(front.first->right, front.second+1));
            
            q.pop();
        }

        if(cnt > 0)  result.push_back((double)sum/cnt);

        return result;
    }
};