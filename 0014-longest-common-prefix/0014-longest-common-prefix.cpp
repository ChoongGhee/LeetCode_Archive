class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;

        int size = 200;
        for(string temp : strs) if(size>temp.size()) size = temp.size();

        int num = strs.size();
        for(int i = 0; i<size;i++){
            char st = strs[0][i];
            for(int j=1;j<num;j++) if(st != strs[j][i]) return result;
            result.push_back(st);
        }

        return result;
    }
};