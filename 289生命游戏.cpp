//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    void gameOfLife(vector<vector<int>>& board) {
//        int m = board.size();
//        int n = board[0].size();
//        auto bd = board;//原矩阵复制品
//        int pos[3] = { -1,0,1 };//用来遍历周围的八个细胞
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                int livecells = 0;
//                for (int i = 0; i < 3; i++)
//                    for (int j = 0; j < 3; j++)
//                    {
//                        if (pos[i] == 0 && pos[j] == 0) continue;//当前细胞不用遍历
//                        else
//                        {
//                            int r = row + pos[i];
//                            int c = column + pos[j];
//                            if ((r >= 0 && r < m) && (c >= 0 && c < n) && bd[r][c] == 1) livecells++;//如果当前位置合法且是活细胞
//                        }
//                    }
//                if ((livecells < 2 || livecells>3) && bd[row][column] == 1) board[row][column] = 0;//规则1和3
//                else if (livecells == 3 && bd[row][column] == 0) board[row][column] = 1;//规则4
//            }
//    }
//};//需要额外O(mn)空间
//
//class Solution {
//public:
//    void gameOfLife(vector<vector<int>>& board) {
//        int m = board.size();
//        int n = board[0].size();
//        int pos[3] = { -1,0,1 };//用来遍历周围的八个细胞
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                int livecells = 0;
//                for (int i = 0; i < 3; i++)
//                    for (int j = 0; j < 3; j++)
//                    {
//                        if (pos[i] == 0 && pos[j] == 0) continue;//当前细胞不用遍历
//                        int r = row + pos[i];
//                        int c = column + pos[j];
//                        if ((r >= 0 && r < m) && (c >= 0 && c < n) && abs(board[r][c]) == 1) livecells++;
//                    }//如果当前位置合法且是活细胞,这里用绝对值是因为-1表示之前这个细胞是活着的，由于只做整体更新，所以仍将其当活着的
//                if ((livecells < 2 || livecells>3) && board[row][column] == 1) board[row][column] = -1;//规则1和3,用-1表示原来活着现在死了
//                else if (livecells == 3 && board[row][column] == 0) board[row][column] = 2;//规则4，用2表示复活的细胞
//            }
//        for (int row = 0; row < m; row++)
//            for (int column = 0; column < n; column++)
//            {
//                if (board[row][column] == 2) board[row][column] = 1;
//                else if (board[row][column] == -1) board[row][column] = 0;
//            }
//    }
//};//只占用常数空间