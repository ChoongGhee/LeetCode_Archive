class Solution {
public:
    const vector<vector<int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1},  {1, 0}, {1, 1}
};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int row = temp.size();
        int col = temp[0].size();

        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                int cnt = 0;
                for(auto check : directions)if(-1< i+check[0] && i+check[0] < row && -1 < j+check[1] && j+check[1] < col && temp[i+check[0]][j+check[1]]) cnt++;
                if(temp[i][j] && (cnt == 2 || cnt == 3)) board[i][j] = 1;
                else board[i][j] = 0;

                if(!temp[i][j] && cnt == 3) board[i][j] = 1;
                else board[i][j] - 0;
            }
        }
    }
};