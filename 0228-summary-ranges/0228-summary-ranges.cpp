class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if(nums.size() == 0) return result;

        vector<int> temp;

        for(auto val : nums){
            if(temp.empty()){
                temp.push_back(val);
            }
            else if(temp.back() + 1 == val) temp.push_back(val);
            else{
                if(temp.size() == 1) result.push_back(to_string(temp.front()));
                else  result.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));
                temp.clear();
                temp.push_back(val);
            }
        }

        if(temp.size() == 1) result.push_back(to_string(temp[0]));
        else result.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));

        return result;
    }
};