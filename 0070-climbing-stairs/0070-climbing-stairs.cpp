class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;

        int* dp = new int[2];
        dp[0] = 1;
        dp[1] = 1;

        for(char i =2;i<n+1;i++){
            int temp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = temp;
        }

        return dp[1];
    }
};