class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size() == 1){
            if(k == nums[0]) return 0;
            else if(k> nums[0]) return -1;
            else if(k<nums[0]) return 1;
        }

        vector<char> table(101, 0);

        for(int idx:nums){
            if(idx < k) return -1;
            table[idx]++;
        }

        char temp = 0;

        char cnt = 0;
        for(char i = 100; k-1<i;i--){
            if(!table[i]) continue;

            if(!temp) temp = i;
            else{
                temp = i;
                cnt++;
            }
        }
        
        return temp!=k ? cnt+1 : cnt;
    }
};