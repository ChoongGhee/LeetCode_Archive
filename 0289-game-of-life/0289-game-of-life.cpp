class Solution {
    public:
        // 이것도 최적화 가능
    //     const vector<vector<int>> directions = {
    //     {-1, -1}, {-1, 0}, {-1, 1},
    //     {0, -1},          {0, 1},
    //     {1, -1},  {1, 0}, {1, 1}
    // };
        void gameOfLife(vector<vector<int>>& board) {
            // vector<vector<int>> temp = board;
            int row = board.size();
            int col = board[0].size();
    
            for(int i =0;i<row;i++){
                for(int j = 0;j<col;j++){
                    int cnt = 0;
                    
                    for(int dx = -1;dx <= 1; dx++){
                        for(int dy = -1;dy<=1;dy++){
                            if(dx == 0 && dy == 0) continue;
                            if(-1< i+dx && i+dx < row && -1 < j+dy && j+dy < col && (board[i+dx][j+dy] == 1 || board[i+dx][j+dy] == 3)) cnt++;
                        }
                    }   
                    
                    if(board[i][j]) {if(cnt < 2 || cnt >3) board[i][j] = 3;}
                    else if(cnt == 3) board[i][j] = 2;
                    // 공간복잡도 최적화 : 상태 코드 4가지를 사용
                    // 0, 1 그대로
                    // 2 죽었는데 살아남. 이전엔 죽었다는 값
                    // 3 살았는데 죽음. 이전엔 살아있음.
                    // if((temp[i][j] && (cnt == 2 || cnt == 3)) || (!temp[i][j] && cnt == 3)) board[i][j] = 1;
                    // else board[i][j] = 0;
    
                    // 실수 : 두 조건문 을 사용해 덮어씌워지는 현상이 일어나서 잘못됨
                    // if(temp[i][j] && (cnt == 2 || cnt == 3)) board[i][j] = 1;
                    // else board[i][j] = 0;
                    
                    // if(!temp[i][j] && cnt == 3) board[i][j] = 1;
                    // else board[i][j] = 0;
                }
            }
    
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(board[i][j] == 2) board[i][j] = 1;
                    else if(board[i][j] == 3) board[i][j] = 0;
                }
            }
        }
    };

