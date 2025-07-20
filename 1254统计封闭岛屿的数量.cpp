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
//        // 如果出界，说明已经触及边界，不能是封闭岛屿
//        if (i < 0 || i >= m || j < 0 || j >= n)
//            return false;
//        // 如果是水域 或者 已访问，不需要处理，当前方向视为“封闭”（返回 true）
//        if (grid[i][j] == 1 || visited[i][j])
//            return true;
//
//        // 标记当前陆地为已访问
//        visited[i][j] = true;
//
//        // 四个方向递归，判断是否有方向触及边界
//        bool up = DFS(grid, visited, i - 1, j);
//        bool down = DFS(grid, visited, i + 1, j);
//        bool left = DFS(grid, visited, i, j - 1);
//        bool right = DFS(grid, visited, i, j + 1);
//
//        // 只要有一个方向不封闭（触及边界），整个岛屿就不封闭
//        return up && down && left && right;
//    }
//    int closedIsland(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size(), count = 0;
//        vector<vector<bool>> visited(m, vector<bool>(n, false));
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 0 && !visited[i][j]) {//只有为陆地才进入循环
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
//        vector<pair<int, int>>directions = { {0,1},{0,-1},{1,0},{-1,0} };//四个方向
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
//                        if (point.first == 0||point.second==0||point.first==m-1||point.second==n-1) closed = false;//如果当陆地在边界上肯定不可能是封闭的
//                        for (auto direction : directions) {
//                            int x = point.first + direction.first, y = point.second + direction.second;
//                            if (x < m && y < n && x>0 && y>0 && grid[i][j] == 0 && !visited[i][j])//保证遍历的点是陆地且没有越界
//                            {
//                                q.push({ x,y });
//                                visited[x][y] = true;
//                            }
//                        }
//                    }
//                    if (closed) res++;//遍历完一个岛屿后如果仍是封闭的，加入结果
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