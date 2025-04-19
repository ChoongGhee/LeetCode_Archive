class Solution {
public:
    bool isSubsequence(const string s, const string t) {
        int sidx = 0;
        int tidx = 0;

        while(sidx<s.size() && tidx<t.size()){
            if(s[sidx] == t[tidx]){
                sidx++;
            }
            tidx++;
        }

        if(sidx == s.size()) return true;
        else return false;

    }
};