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
//        int row[9][9];//��¼ÿһ������1-9���ִ���
//        int column[9][9];//��¼ÿһ������1-9���ִ���
//        int subboxes[3][3][9];//��¼ÿһ���ӿ�����1-9���ִ�����3*3��Ӧ9���ӿ飬9��Ӧ����1-9�ڸ��ӿ��г��ִ���������ͨ��i,j/3�ж�����һ���ӿ���
//        memset(row, 0, sizeof(row));
//        memset(column, 0, sizeof(column));
//        memset(column, 0, sizeof(column));
//        for(int i=0;i<9;i++)
//            for (int j = 0; j < 9; j++)
//            {
//                if (board[i][j] != '.')
//                {
//                    int index = board[i][j] - '0' - 1;//��Ϊ������0��ʼ����-1
//                    if (++row[i][index] > 1 || ++column[j][index] > 1 || ++subboxes[i / 3][j / 3][index]> 1)//�������������ж�(ǰ�������ȼ����ж�)��ʡȥ�ֿ�д�ı�Ҫ
//                        return false;
//                }
//            }
//        return true;
//
//    }
//};