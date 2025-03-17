class Solution {
    public:
        int reverse(int x) {
            bool is_minus = (x & (1<<31));
            x = x < 0 ? -x : x;
           
            long long result = 0;

            while(x > 0){
                result = result*10 + x%10;
                x /= 10;
            }
            
            if(result > INT_MAX) return 0;

            return is_minus ? -result : result;
        }
    };