//#include<iostream>
//#include<vector>
//#include<queue>
//#include<utility>
//using namespace std;
//
//class Solution1 {
//public:
//    void DFS(vector<vector<char>>& grid, int i, int j) {
//        int m = grid.size(), n = grid[0].size();
//        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;//超范围或者不是岛屿就返回
//        grid[i][j] = '0';//标记为已访问
//        DFS(grid, i - 1, j);//上
//        DFS(grid, i, j-1);//左
//        DFS(grid, i+1, j);//下
//        DFS(grid, i, j+1);//右
//    }//深度优先搜索
//    
//    int numIslands(vector<vector<char>>& grid) {
//        int res = 0;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                if (grid[i][j] == '1') {
//                    DFS(grid, i, j);
//                    res++;
//                }
//            }
//        }
//        return res;
//    }
//};//如果不能改变原数组grid的话就要建立一个bool类型的visited数组
//
//
//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        int res = 0;
//        vector<vector<bool>>visited(m, vector<bool>(n, false));
//        vector<pair<int, int>>directions = { {0,1},{0,-1},{1,0},{-1,0} };//四个方向
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1' && !visited[i][j])//如果该岛屿没有被访问过
//                {
//                    queue<pair<int, int>>q;//队列中存放接下来要遍历的节点位置
//                    q.push({ i,j });
//                    res++;
//                    visited[i][j] = true;
//                    while (!q.empty()) {
//                        auto p = q.front(); q.pop();//取出当前节点的坐标
//                        for (auto direction : directions) {//遍历当前坐标的四个方向
//                            int x = p.first + direction.first, y = p.second + direction.second;
//                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visited[x][y]) {//如果当前方向是岛屿
//                                q.push({ x,y });//加入到队列中用于后续的遍历
//                                visited[x][y] = true;//将这个方向标记为遍历过
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};