class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // ASCII 문자용 배열 사용 (128개의 가능한 ASCII 값마다 하나씩)
    vector<bool> seen(128, false);
    
    int left = 0, right = 0;
    int maxLength = 0;
    
    while (right < s.length()) {
        char currentChar = s[right];
        
        // 이미 윈도우에 있는 문자라면
        if (seen[currentChar]) {
            // 중복이 제거될 때까지 왼쪽에서 윈도우 축소
            // 왼쪽 포인터를 이동하면서 지나간 문자들의
            // seen 값을 false로 바꿔줍니다
            while (s[left] != currentChar) {
                seen[s[left]] = false;
                left++;
            }
            // 중복된 문자 자체도 윈도우에서 제거
            seen[s[left]] = false;
            left++;
        }
        
        // 현재 문자를 윈도우에 추가하고 확장
        seen[currentChar] = true;
        right++;
        
        // 최대 길이 업데이트
        maxLength = max(maxLength, right - left);
    }
    
    return maxLength;
}
};