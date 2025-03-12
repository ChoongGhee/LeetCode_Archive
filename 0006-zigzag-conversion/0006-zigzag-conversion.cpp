string convert(string s, int numRows) {
    if(numRows == 1 || numRows >= s.size()) return s;
    
    string result(s.size(), 0); // 결과 문자열을 미리 할당
    int index = 0; // 결과 문자열의 인덱스
    
    // 각 행에 대해
    for(int row = 0; row < numRows; row++) {
        // 첫 행과 마지막 행은 2*(numRows-1) 간격으로 문자가 위치
        // 중간 행은 추가 문자가 있음
        int step = 2 * (numRows - 1);
        
        for(int j = row; j < s.size(); j += step) {
            result[index++] = s[j]; // 주 위치의 문자 추가
            
            // 중간 행에 대해 추가 문자 계산
            if(row > 0 && row < numRows - 1) {
                int secondJ = j + step - 2 * row;
                if(secondJ < s.size()) {
                    result[index++] = s[secondJ]; // 보조 위치의 문자 추가
                }
            }
        }
    }
    
    return result;
}