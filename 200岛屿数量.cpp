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
//        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;//����Χ���߲��ǵ���ͷ���
//        grid[i][j] = '0';//���Ϊ�ѷ���
//        DFS(grid, i - 1, j);//��
//        DFS(grid, i, j-1);//��
//        DFS(grid, i+1, j);//��
//        DFS(grid, i, j+1);//��
//    }//�����������
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
//};//������ܸı�ԭ����grid�Ļ���Ҫ����һ��bool���͵�visited����
//
//
//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        int res = 0;
//        vector<vector<bool>>visited(m, vector<bool>(n, false));
//        vector<pair<int, int>>directions = { {0,1},{0,-1},{1,0},{-1,0} };//�ĸ�����
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1' && !visited[i][j])//����õ���û�б����ʹ�
//                {
//                    queue<pair<int, int>>q;//�����д�Ž�����Ҫ�����Ľڵ�λ��
//                    q.push({ i,j });
//                    res++;
//                    visited[i][j] = true;
//                    while (!q.empty()) {
//                        auto p = q.front(); q.pop();//ȡ����ǰ�ڵ������
//                        for (auto direction : directions) {//������ǰ������ĸ�����
//                            int x = p.first + direction.first, y = p.second + direction.second;
//                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visited[x][y]) {//�����ǰ�����ǵ���
//                                q.push({ x,y });//���뵽���������ں����ı���
//                                visited[x][y] = true;//�����������Ϊ������
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};