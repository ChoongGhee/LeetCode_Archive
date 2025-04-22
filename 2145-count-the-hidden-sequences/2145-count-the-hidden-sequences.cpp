class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        long long min_val, max_val, cur;
        min_val = 0;
        max_val = 0;
        cur = 0;

        for(auto val : differences){
            cur += val;
            min_val = std::min(min_val, cur);
            max_val = std::max(max_val, cur);
        }

        long long min_start = lower - min_val;
        long long max_start = upper - max_val;
    
        if (min_start > max_start) return 0;
        return std::max(0LL, max_start - min_start + 1);
    }

};