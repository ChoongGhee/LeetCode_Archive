class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        if (k == 0) return; 
        
        vector<int> temp = nums;
        
        for (int i = 0; i < k; i++) nums[i] = temp[n - k + i];
        for (int i = 0; i < n - k; i++) nums[k + i] = temp[i];
    }
};