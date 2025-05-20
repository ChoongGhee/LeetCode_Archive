class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int result;
        
        
        for(auto val : nums){
            if(cnt == 0) result = val;

            if(result == val) cnt++;
            else cnt--;
        }

        return result;
    }
};