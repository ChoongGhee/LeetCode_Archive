class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        // prefix를 0으로 하는 이유는 수식의 x-prefix(최소 or 최대)값인 prefix를 그대로 구할 수 있게됨. 그것을 활용해 x의 범위를 구할 수 있음.
        long long prefix = 0;
        int max_val = -100001;
        int min_val = 100001;
        for(int val : differences){
            prefix += val;
            if(min_val > prefix) min_val = prefix;
            if(max_val < prefix) max_val = prefix;
        }

        // 두가지 조건에 맞는 값을 정하는 부분
        long long low = max((long long)lower, (long long)lower - min_val);
        long long high = min((long long)upper, (long long)upper - max_val);

        if(low > high) return 0;
        
        return high - low +1;
    }

};