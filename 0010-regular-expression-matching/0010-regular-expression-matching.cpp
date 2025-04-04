class Solution {
    public:
        bool isMatch(string s, string p) {
        // vecotr<vector> bool 과 new **bool을 봤을 때 벡터 쪽이 오버해드가 있어 느리다고 판단했음. 속도 측면에선 맞음. but 메모리 측면에선 크게 달랐음 이유는 옵시디언에 정리. so 속도차이 미미(n배열이 최대 20x20이기 때문), 메모리 사용량은 크기 때문에 vector쓰기로 함.
            unordered_map<string, bool> memo;
            return dfs(s, p, 0, 0, memo);

            int m = s.length();
            int n = p.length();

            vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
            dp[0][0] = true;
            // 빈 문자열에 대한 패턴 초기화
            // 예: p = "a*b*" 같은 패턴은 빈 문자열과 일치 가능
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[0][j] = dp[0][j-2]; // '*'는 앞 문자와 함께 0번 사용할 수 있음
                }
            }
            // DP 테이블 채우기
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (p[j-1] == '*') {
                        // '*'인 경우 두 가지 가능성:
                        // 1. '*'와 앞 문자를 무시 (0번 사용)
                        // 2. 앞 문자가 s의 현재 문자와 일치하면, s의 이전 문자에 대한 결과를 사용
                        dp[i][j] = dp[i][j-2]; // '*'와 앞 문자를 무시
                        
                        if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    } 
                    else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                        // 현재 문자가 일치하는 경우
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
            
        return dp[m][n];

        }


        bool dfs(const string& s, const string& p, int i, int j, unordered_map<string, bool>& memo) {
            // 종료 조건 확인
            if (j == p.length()) return i == s.length();
            
            // 현재 상태를 키로 사용
            string key = to_string(i) + "," + to_string(j);
            
            // 이미 계산된 결과가 있으면 반환
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }
            
            // 현재 문자 매칭 여부 확인
            bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            
            bool result;
            if ((j+1 < p.size()) && p[j+1] == '*') {
                // '*' 패턴일 경우: 0번 매칭하거나 1번 이상 매칭
                result = dfs(s, p, i, j+2, memo) || (match && dfs(s, p, i+1, j, memo));
            } else {
                // A single character match
                result = match && dfs(s, p, i+1, j+1, memo);
            }
            
            // 결과 저장하고 반환
            memo[key] = result;
            return result;
        }
    };