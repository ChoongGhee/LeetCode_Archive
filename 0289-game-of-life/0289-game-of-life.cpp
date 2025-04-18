class Solution {
public:
    const vector<vector<int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1},  {1, 0}, {1, 1}
};
    void gameOfLife(vector<vector<int>>& board) {
        // vector<vector<int>> temp = board;
        int row = board.size();
        int col = board[0].size();

        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                int cnt = 0;
                for(auto& check : directions)if(-1< i+check[0] && i+check[0] < row && -1 < j+check[1] && j+check[1] < col && (board[i+check[0]][j+check[1]] == 1 || board[i+check[0]][j+check[1]] == 3)) cnt++;
                
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