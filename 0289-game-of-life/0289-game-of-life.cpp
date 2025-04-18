class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int cnt = 0;
                
                // 직접 8방향 이웃 확인 (방향 배열 없이)
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(dx == 0 && dy == 0) continue; // 자기 자신 제외
                        
                        int ni = i + dx;
                        int nj = j + dy;
                        
                        if(ni >= 0 && ni < row && nj >= 0 && nj < col && 
                           (board[ni][nj] == 1 || board[ni][nj] == 3)) {
                            cnt++;
                        }
                    }
                }
                
                if(board[i][j] == 1) {
                    // 살아있는 셀
                    if(cnt < 2 || cnt > 3) {
                        board[i][j] = 3; // 살아있는 상태 -> 죽은 상태
                    }
                } else {
                    // 죽은 셀
                    if(cnt == 3) {
                        board[i][j] = 2; // 죽은 상태 -> 살아있는 상태
                    }
                }
            }
        }

        // 최종 상태로 변환
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};