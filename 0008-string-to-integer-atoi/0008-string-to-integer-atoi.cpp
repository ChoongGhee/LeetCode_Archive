class Solution {
    public:
        int myAtoi(string s) {
        int idx = 0;
        while(s[idx] == ' ') idx++;
        
        if(idx == s.length()) return 0;

        bool is_minus = false;

        if(s[idx] == '-') {
            is_minus = true;
            idx++;
        }
        else if(s[idx] == '+') idx++;
        
        long long result = 0;

        while(idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
            result = result*10 + s[idx] - '0';

            if(is_minus && -result < INT_MIN) return INT_MIN;
            if(!is_minus && result > INT_MAX) return INT_MAX;
            
            idx++;
        }
        
        return is_minus ? -result : result;
        }
    };