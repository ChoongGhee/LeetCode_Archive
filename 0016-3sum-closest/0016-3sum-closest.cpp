class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];
        int result = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];

                // cout << sum << " " << result << endl;

                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    return sum;
                }

                if(abs(target - result) > abs(target - sum)) result = sum;
            }
        }

        return result;
    }
};
