class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l < r){
            if(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))) {
                l++;
                continue;
            }

            if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
                continue;
            }

            char l_val = s[l];
            char r_val = s[r];

            if(l_val > 91) l_val -= 32;
            if(r_val > 91) r_val -= 32;

            if(l_val != r_val) {
                return false;
            }
            
            l++;
            r--;
        }

        return true;
    }
};