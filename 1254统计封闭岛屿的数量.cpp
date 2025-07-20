//#include<iostream>
//#include<vector>
//#include<queue>
//#include<utility>
//using namespace std;
//
//class Solution {
//public:
//    bool DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
//        int m = grid.size(), n = grid[0].size();
//
//        // ������磬˵���Ѿ������߽磬�����Ƿ�յ���
//        if (i < 0 || i >= m || j < 0 || j >= n)
//            return false;
//        // �����ˮ�� ���� �ѷ��ʣ�����Ҫ������ǰ������Ϊ����ա������� true��
//        if (grid[i][j] == 1 || visited[i][j])
//            return true;
//
//        // ��ǵ�ǰ½��Ϊ�ѷ���
//        visited[i][j] = true;
//
//        // �ĸ�����ݹ飬�ж��Ƿ��з��򴥼��߽�
//        bool up = DFS(grid, visited, i - 1, j);
//        bool down = DFS(grid, visited, i + 1, j);
//        bool left = DFS(grid, visited, i, j - 1);
//        bool right = DFS(grid, visited, i, j + 1);
//
//        // ֻҪ��һ�����򲻷�գ������߽磩����������Ͳ����
//        return up && down && left && right;
//    }
//    int closedIsland(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size(), count = 0;
//        vector<vector<bool>> visited(m, vector<bool>(n, false));
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 0 && !visited[i][j]) {//ֻ��Ϊ½�زŽ���ѭ��
//                    if (DFS(grid, visited, i, j)) {
//                        count++;
//                    }
//                }
//            }
//        }
//        return count;
//    }
//};
//
//class Solution {
//public:
//    int closedIsland(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size(), count = 0;
//        vector<vector<bool>> visited(m, vector<bool>(n, false));
//        vector<pair<int, int>>directions = { {0,1},{0,-1},{1,0},{-1,0} };//�ĸ�����
//        int res = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 0 && !visited[i][j]) {
//                    queue<pair<int, int>>q;
//                    q.push({ i,j });
//                    visited[i][j] = true;
//                    bool closed = true;
//                    while (!q.empty()) {
//                        auto point = q.front(); q.pop();
//                        if (point.first == 0||point.second==0||point.first==m-1||point.second==n-1) closed = false;//�����½���ڱ߽��Ͽ϶��������Ƿ�յ�
//                        for (auto direction : directions) {
//                            int x = point.first + direction.first, y = point.second + direction.second;
//                            if (x < m && y < n && x>0 && y>0 && grid[i][j] == 0 && !visited[i][j])//��֤�����ĵ���½����û��Խ��
//                            {
//                                q.push({ x,y });
//                                visited[x][y] = true;
//                            }
//                        }
//                    }
//                    if (closed) res++;//������һ�������������Ƿ�յģ�������
//                }
//            }
//        }
//        return res;
//    }
//};
//
//
//int main() {
//    vector<vector<int>>grid = { {1,1,1,1,1,1,1,0},{1,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0} };
//    Solution a;
//    cout << a.closedIsland(grid);
//}