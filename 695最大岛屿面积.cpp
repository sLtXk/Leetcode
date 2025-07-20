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
//            //�Լ�+4�������ϵ����
//        }
//        return 0;//��������������0
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
//};//DFS�ⷨ
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
//                    int area = 1;//��ʱ��ǰ�ڵ��Ѿ�ȷ��Ϊ���죬���Ϊ1
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
//                    }//������һ������˵����ǰ�����Ѿ�������
//                    maxArea = max(area, maxArea);//������������
//                }
//            }
//        }
//        return maxArea;
//    }
//};//BFS�ⷨ