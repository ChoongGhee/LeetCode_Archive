class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dp;
        dp.resize('z' - 'a' +1, 0);
        
        for(auto v : magazine) dp[v - 'a']++;

        for(auto v1 : ransomNote){
            if(dp[v1 - 'a'] == 0) return false;
            
            dp[v1 - 'a']--;
        }
        return true;
    }
};