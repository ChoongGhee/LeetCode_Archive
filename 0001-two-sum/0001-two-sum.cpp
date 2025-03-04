class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> numWithIdx;
        for (int i = 0; i < nums.size(); i++) {
            numWithIdx.push_back({nums[i], i});
        }
        
         sort(numWithIdx.begin(), numWithIdx.end());

        int left = 0;
        int right = numWithIdx.size() - 1;
        
        while (left < right) {
            int sum = numWithIdx[left].first + numWithIdx[right].first;
            
            if (sum == target) {
                // 원래 인덱스 반환
                return {numWithIdx[left].second, numWithIdx[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {-1, -1}; // 해를 찾지 못한 경우
    
    }
};