//#include<iostream>
//#include<vector>
//#include<queue>
//#include<utility>
//using namespace std;
//
//class Solution {
//public:
//    void dfs(vector<vector<char>>& board, int i, int j) {
//        int m = board.size(), n = board[0].size();
//        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;//如果在边界外或者是X就直接返回
//        //这里不是和边界相连的O不会被访问到，因为到X就直接返回了
//
//        board[i][j] = '#'; // 标记：和边界相连的 O，不能翻转
//        dfs(board, i + 1, j);
//        dfs(board, i - 1, j);
//        dfs(board, i, j + 1);
//        dfs(board, i, j - 1);
//    } 
//
//    void solve(vector<vector<char>>& board) {
//        if (board.empty() || board[0].empty()) return;
//        int m = board.size(), n = board[0].size();
//
//        // 从四个边界开始 DFS，把所有和边界相连的 'O' 标记成 '#'
//        for (int i = 0; i < m; ++i) {
//            dfs(board, i, 0);
//            dfs(board, i, n - 1);
//        }
//        for (int j = 0; j < n; ++j) {
//            dfs(board, 0, j);
//            dfs(board, m - 1, j);
//        }
//
//        // 再遍历一次，把所有剩下的 'O' 改为 'X'，把 '#' 还原成 'O'
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (board[i][j] == 'O') board[i][j] = 'X';
//                else if (board[i][j] == '#') board[i][j] = 'O';
//            }
//        }
//    }
//};//DFS，反向思路，将和边界相连的O标记为不能变化，剩下的O就是可以变为X的了
//
//class Solution {
//public:
//
//
//    void solve(vector<vector<char>>& board) {
//        if (board.empty() || board[0].empty()) return;
//        int m = board.size(), n = board[0].size();
//        queue<pair<int, int>> q;
//
//        // 遍历边界，把所有边界上的 O 入队
//        auto enqueue = [&](int i, int j) {
//            if (board[i][j] == 'O') {
//                board[i][j] = '#'; // 先标记一下（表示不该被替换）
//                q.push({ i, j });
//            }
//        };
//
//        for (int i = 0; i < m; ++i) {
//            enqueue(i, 0);
//            enqueue(i, n - 1);
//        }
//        for (int j = 0; j < n; ++j) {
//            enqueue(0, j);
//            enqueue(m - 1, j);
//        }
//
//        // 四个方向
//        vector<pair<int, int>> dirs{ {1,0},{-1,0},{0,1},{0,-1} };
//
//        // BFS 找所有与边界 O 连通的 O
//        while (!q.empty()) {
//            auto point = q.front(); q.pop();
//            for (auto dir : dirs) {
//                int nx = point.first + dir.first, ny = point.second + dir.second;
//                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
//                    board[nx][ny] = '#';
//                    q.push({ nx, ny });
//                }
//            }
//        }
//
//        // 最终处理：把剩下的 O 变成 X，把 # 还原成 O
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (board[i][j] == 'O') board[i][j] = 'X';
//                else if (board[i][j] == '#') board[i][j] = 'O';
//            }
//        }
//    }
//};
//
//
//
//
//int main() {
//    vector<vector<char>> board = { {'X','X','X','X'},{'X','O','O','X'} ,{'X','X','O','X'},{'X','O','X','X'} };
//    Solution a;
//    a.solve(board);
//}