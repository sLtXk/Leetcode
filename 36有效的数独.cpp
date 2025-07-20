//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        int row[9][9];//记录每一行数字1-9出现次数
//        int column[9][9];//记录每一列数字1-9出现次数
//        int subboxes[3][3][9];//记录每一个子块数字1-9出现次数，3*3对应9个子块，9对应数字1-9在该子块中出现次数，可以通过i,j/3判断在哪一个子块内
//        memset(row, 0, sizeof(row));
//        memset(column, 0, sizeof(column));
//        memset(column, 0, sizeof(column));
//        for(int i=0;i<9;i++)
//            for (int j = 0; j < 9; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    int index = board[i][j] - '0' - 1;//因为索引从0开始所以-1
//                    if (++row[i][index] > 1 || ++column[j][index] > 1 || ++subboxes[i / 3][j / 3][index]> 1)//这里先自增再判断(前置自增先加再判断)，省去分开写的必要
//                        return false;
//                }
//            }
//        return true;
//
//    }
//};