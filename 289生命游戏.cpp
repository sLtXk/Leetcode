//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    void gameOfLife(vector<vector<int>>& board) {
//        int m = board.size();
//        int n = board[0].size();
//        auto bd = board;//ԭ������Ʒ
//        int pos[3] = { -1,0,1 };//����������Χ�İ˸�ϸ��
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                int livecells = 0;
//                for (int i = 0; i < 3; i++)
//                    for (int j = 0; j < 3; j++)
//                    {
//                        if (pos[i] == 0 && pos[j] == 0) continue;//��ǰϸ�����ñ���
//                        else
//                        {
//                            int r = row + pos[i];
//                            int c = column + pos[j];
//                            if ((r >= 0 && r < m) && (c >= 0 && c < n) && bd[r][c] == 1) livecells++;//�����ǰλ�úϷ����ǻ�ϸ��
//                        }
//                    }
//                if ((livecells < 2 || livecells>3) && bd[row][column] == 1) board[row][column] = 0;//����1��3
//                else if (livecells == 3 && bd[row][column] == 0) board[row][column] = 1;//����4
//            }
//    }
//};//��Ҫ����O(mn)�ռ�
//
//class Solution {
//public:
//    void gameOfLife(vector<vector<int>>& board) {
//        int m = board.size();
//        int n = board[0].size();
//        int pos[3] = { -1,0,1 };//����������Χ�İ˸�ϸ��
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                int livecells = 0;
//                for (int i = 0; i < 3; i++)
//                    for (int j = 0; j < 3; j++)
//                    {
//                        if (pos[i] == 0 && pos[j] == 0) continue;//��ǰϸ�����ñ���
//                        int r = row + pos[i];
//                        int c = column + pos[j];
//                        if ((r >= 0 && r < m) && (c >= 0 && c < n) && abs(board[r][c]) == 1) livecells++;
//                    }//�����ǰλ�úϷ����ǻ�ϸ��,�����þ���ֵ����Ϊ-1��ʾ֮ǰ���ϸ���ǻ��ŵģ�����ֻ��������£������Խ��䵱���ŵ�
//                if ((livecells < 2 || livecells>3) && board[row][column] == 1) board[row][column] = -1;//����1��3,��-1��ʾԭ��������������
//                else if (livecells == 3 && board[row][column] == 0) board[row][column] = 2;//����4����2��ʾ�����ϸ��
//            }
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                if (board[row][column] == 2) board[row][column] = 1;
//                else if (board[row][column] == -1) board[row][column] = 0;
//            }
//    }
//};//ֻռ�ó����ռ�