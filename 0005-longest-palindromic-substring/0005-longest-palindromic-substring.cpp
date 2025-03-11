#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        
        int start = 0, maxLength = 1;
        
        // 모든 가능한 중심점에서 확장
        for (int i = 0; i < s.length(); i++) {
            // 홀수 길이 회문 (중심이 한 문자)
            expandAroundCenter(s, i, i, start, maxLength);
            
            // 짝수 길이 회문 (중심이 두 문자 사이)
            if (i < s.length() - 1) {
                expandAroundCenter(s, i, i + 1, start, maxLength);
            }
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        // 양쪽으로 확장하면서 회문인지 확인
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        // 확장이 끝난 후, 회문의 길이 계산 (left+1부터 right-1까지가 회문)
        int length = right - left - 1;
        if (length > maxLength) {
            maxLength = length;
            start = left + 1;
        }
    }
};