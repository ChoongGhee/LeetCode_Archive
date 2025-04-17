class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        if(k==0) return;

        vector<int> temp = nums;
        
        // 뒤쪽 k개의 요소를 앞으로 이동
        for (int i = 0; i < k; i++) {
            nums[i] = temp[n - k + i];
        }
        
        // 앞쪽 (n-k)개의 요소를 뒤로 이동
        for (int i = 0; i < n - k; i++) {
            nums[k + i] = temp[i];
        }    
    }
};