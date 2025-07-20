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
//        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;//����ڱ߽��������X��ֱ�ӷ���
//        //���ﲻ�Ǻͱ߽�������O���ᱻ���ʵ�����Ϊ��X��ֱ�ӷ�����
//
//        board[i][j] = '#'; // ��ǣ��ͱ߽������� O�����ܷ�ת
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
//        // ���ĸ��߽翪ʼ DFS�������кͱ߽������� 'O' ��ǳ� '#'
//        for (int i = 0; i < m; ++i) {
//            dfs(board, i, 0);
//            dfs(board, i, n - 1);
//        }
//        for (int j = 0; j < n; ++j) {
//            dfs(board, 0, j);
//            dfs(board, m - 1, j);
//        }
//
//        // �ٱ���һ�Σ�������ʣ�µ� 'O' ��Ϊ 'X'���� '#' ��ԭ�� 'O'
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (board[i][j] == 'O') board[i][j] = 'X';
//                else if (board[i][j] == '#') board[i][j] = 'O';
//            }
//        }
//    }
//};//DFS������˼·�����ͱ߽�������O���Ϊ���ܱ仯��ʣ�µ�O���ǿ��Ա�ΪX����
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
//        // �����߽磬�����б߽��ϵ� O ���
//        auto enqueue = [&](int i, int j) {
//            if (board[i][j] == 'O') {
//                board[i][j] = '#'; // �ȱ��һ�£���ʾ���ñ��滻��
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
//        // �ĸ�����
//        vector<pair<int, int>> dirs{ {1,0},{-1,0},{0,1},{0,-1} };
//
//        // BFS ��������߽� O ��ͨ�� O
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
//        // ���մ�����ʣ�µ� O ��� X���� # ��ԭ�� O
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