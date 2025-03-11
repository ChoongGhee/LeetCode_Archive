
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        
        string result;
        for(int i = 0; i < s.size(); i++){
            // 홀수 길이 회문 확인 (중심이 한 문자)
            string temp1 = expandAroundCenter(s, i, i);
            if(temp1.size() > result.size()) result = temp1;
            
            // 짝수 길이 회문 확인 (중심이 두 문자 사이)
            if(i < s.size() - 1) {
                string temp2 = expandAroundCenter(s, i, i+1);
                if(temp2.size() > result.size()) result = temp2;
            }
        }
        
        return result;
    }

    string expandAroundCenter(string& s, int left, int right){
        string result;
        
        // 초기 상태가 짝수 길이 시작인 경우 (left != right), 빈 문자열부터 시작
        // 초기 상태가 홀수 길이 시작인 경우 (left == right), 중심 문자 추가
        if(left == right) {
            result.push_back(s[left]);
            left--;
            right++;
        }

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            result = s[left] + result;
            result.push_back(s[right]);
            left--;
            right++;
        }

        return result;
    }
};
