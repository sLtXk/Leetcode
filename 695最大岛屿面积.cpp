//#include<iostream>
//#include<vector>
//#include<queue>
//#include<utility>
//using namespace std;
//
//class Solution1 {
//public:
//    int DFS(vector<vector<int>>& grid, vector<vector<bool>>&visited, int i, int j) {
//        int m = grid.size(), n = grid[0].size();
//        if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1 && !visited[i][j]) {
//            visited[i][j] = true;
//            return 1+DFS(grid, visited, i + 1, j) + DFS(grid, visited, i -1, j) + DFS(grid, visited, i, j+1) + DFS(grid, visited, i , j-1);
//            //自己+4个方向上的面积
//        }
//        return 0;//不满足条件返回0
//    }
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<bool>>visited(m, vector<bool>(n, false));
//        int res = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                res = max(res,DFS(grid, visited, i, j));
//            }
//        }
//        return res;
//    }
//};//DFS解法
//
//
//class Solution {
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<bool>>visited(m, vector<bool>(n, false));
//        vector<pair<int, int>>directions = { {0,1},{0,-1},{1,0},{-1,0} };
//        int maxArea = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 1 && !visited[i][j]) {
//                    queue<pair<int, int>>q;
//                    q.push({ i,j });
//                    visited[i][j] = true;
//                    int area = 1;//此时当前节点已经确认为岛屿，面积为1
//                    while (!q.empty()) {
//                        auto point = q.front(); q.pop();
//                        for (auto& direction : directions) {
//                            int x = point.first + direction.first, y = point.second + direction.second;
//                            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1 && !visited[x][y]) {
//                                area++;
//                                q.push({ x,y });
//                                visited[x][y] = true;
//                            }
//                        }
//                    }//遍历完一个队列说明当前岛屿已经遍历完
//                    maxArea = max(area, maxArea);//更新最大岛屿面积
//                }
//            }
//        }
//        return maxArea;
//    }
//};//BFS解法