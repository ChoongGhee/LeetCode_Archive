#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1 || numRows >= s.size()) return s;

            char** grid = new char* [numRows];
            
            int columns = s.size();
            
            for(int i =0; i < numRows;i++){
                grid[i] = new char [columns]();
            }

            int row = 0;
            int column = 0;
            bool goingDown = true;  // 방향을 나타내는 변수

            for(int i = 0; i < s.size(); i++) {
                grid[row][column] = s[i];
                
                // 여기서 다음 위치를 결정
                if(goingDown) {
                    row++;
                    // 마지막 행에 도달하면 방향 전환
                    if(row == numRows) {
                        goingDown = false;
                        row = numRows - 2;  // 마지막 행에서 한 칸 위로
                        column++;  // 다음 열로 이동
                    }
                } else {
                    row--;
                    column++;  // 위로 이동할 때는 대각선으로 이동하므로 열도 증가
                    // 첫 번째 행에 도달하면 방향 전환
                    if(row < 0) {
                        goingDown = true;
                        row = 1;  // 첫 번째 행 다음으로
                    }
                }
            }

            string result = "";
            for(int i = 0; i < numRows; i++) {
                for(int j = 0; j < columns; j++) {
                    if(grid[i][j] != 0) {  // 문자가 있는 위치만 포함
                        result.push_back(grid[i][j]);
                    }
                }
            }
            
            // 메모리 해제
            for(int i = 0; i < numRows; i++) {
                delete[] grid[i];
            }
            delete[] grid;

            return result;
        }
    };