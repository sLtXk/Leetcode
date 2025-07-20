//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include<string>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        if (prerequisites.size() == 0) return{};
//        unordered_map<int, vector<int>>graph;
//        unordered_map<int, int>indegree;
//        for (auto& p : prerequisites) {
//            int pre = p[1], cur = p[0]; 
//            graph[pre].push_back(cur);//前置课程指向后置课程
//            indegree[cur]++;
//        }//建图
//
//        queue<int>q;
//        for (int i = 0; i < numCourses;i++) {
//            if (indegree[i] == 0) q.push(i);
//        }
//
//        vector<int>res;
//        while (!q.empty()) {
//            int pre = q.front(); q.pop();
//            res.push_back(pre);
//            for (auto& cur : graph[pre]) {
//                indegree[cur]--;
//                if (indegree[cur] == 0) q.push(cur);
//            }
//        }//相当于并行学习多门课程，逐层学习
//        return res.size() == numCourses ? res : vector<int>{};
//    }
//};
//
//class Solution {
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        unordered_map<int, vector<int>>graph;
//        unordered_map<int, int>visited;
//        for (auto& p : prerequisites) {
//            int pre = p[1], cur = p[0];
//            graph[pre].push_back(cur);
//        }
//        vector<int>res;
//        for (int i = 0; i < numCourses; ++i) {
//            if (hasCycleDFS(i, graph, visited,res)) return {};//有环判定为无法学习
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//
//    bool hasCycleDFS(int pre, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& visited,vector<int>&res) {
//        if (visited[pre] == 2) return false;//说明该节点已经访问过，不需要再次访问
//        if (visited[pre] == 1) return true;//递归路径上再次遇到,，存在环，无法学习完所有课程
//
//        visited[pre] = 1;//标记当前节点为正在访问
//        for (auto& cur : graph[pre]) {//对前置课程的所有后置课程进行DFS递归，判断是否成环
//            if (hasCycleDFS(cur, graph, visited,res)) return true;//递归地判断这条路径上是否有环
//        }
//        visited[pre] = 2;//遍历完所有路径后，标记这个前置课程所有路径已经被访问过了
//        res.push_back(pre);//只有在遍历完当前路径时才加入数组,因此此时的结果数组顺序是反的，相当于res数组开头是最深的课程
//        return false;
//    }
//};
