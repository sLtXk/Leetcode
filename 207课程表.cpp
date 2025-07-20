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
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        if (prerequisites.size() == 0) return true;
//        unordered_map<int, vector<int>>graph;//键是前置课程，值是指向的后置课程数组（一门前置课程可能有多门后置课程）
//        unordered_map<int, int>indegree;//节点的入度，代表一门课程有多少门前置课程
//        unordered_set<int>allCourses;//全部课程
//
//        for (auto& p : prerequisites) {
//            allCourses.insert(p[0]);
//            allCourses.insert(p[1]);//放入课程集合中
//            graph[p[1]].push_back(p[0]);//建图,是一个有向无权图
//            indegree[p[0]]++;//由前置课程指向当前课程，当前课程入度+1
//        }//初始化图
//
//        unordered_map<int, bool>reachability;//记录节点的可达性
//        queue<int>q;
//
//        for (const int& course : allCourses) {
//            if (indegree[course] == 0) {
//                q.push(course);
//                reachability[course] = true;
//            }
//        }//将所有没有前继课程的课入队，并标记它们为可达，准备进行BFS
//
//        while (!q.empty()) {
//            int pre_course = q.front(); q.pop();//提取出前置课程
//            for (int& cur_course : graph[pre_course]) {//遍历当前前置课程的所有后置课程
//                indegree[cur_course]--;//当前课程的入度-1，因为我们已经遍历它的一个前置课程
//                if (indegree[cur_course] == 0) {
//                    q.push(cur_course);//如果当前课程所有前置课程都遍历完了，它就可以作为新的前置课程加入队列中
//                    reachability[cur_course] = true;//标记当前课程为可达,只有所有前置课程都遍历完了才标记为可达
//                }
//            }
//        }//拓扑排序+广度优先搜索，搜索前置课程所有能达到的课程，并将它们依次加入队列中，标记它们的可达性
//
//        for (const int& course : allCourses) {
//            if (reachability.find(course) == reachability.end()) return false;//如果在所有课程中有一个不可达的课程，则不能学习完所有课程
//        }
//        return true;
//    }
//};
//
//
//class Solution {
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        if (prerequisites.empty()) return true;
//
//        unordered_map<int, vector<int>> graph; // 建图：键是前置课程，值是它所影响的后置课程列表
//        vector<int> indegree(numCourses, 0);   // 每门课程的入度
//
//         //初始化图和入度表
//        for (auto& p : prerequisites) {
//            int cur = p[0], pre = p[1];
//            graph[pre].push_back(cur); // 从前置课程指向当前课程
//            indegree[cur]++;           // 当前课程入度 +1
//        }
//
//        queue<int> q;
//        int finished = 0; // 记录已完成课程数量（拓扑排序中出队的课程数）
//
//         //将所有入度为 0 的课程入队（即没有前置要求的课程）
//        for (int i = 0; i < numCourses; ++i) {
//            if (indegree[i] == 0) {
//                q.push(i);
//            }
//        }//这里即使indegree[i]不存在也没关系，说明有些课程不存在前置课程，没有出现在prerequisites数组中，其本身就是个孤立点
//
//         //拓扑排序（BFS）
//        while (!q.empty()) {
//            int course = q.front(); q.pop();
//            finished++; // 成功完成一门课程
//
//            for (int& next : graph[course]) {
//                indegree[next]--;
//                if (indegree[next] == 0) {
//                    q.push(next); // 当前课程的所有前置课已完成，可以学习
//                }
//            }
//        }
//
//        // 如果完成课程数 == 总课程数，说明可以完成全部课程
//        return finished == numCourses;
//    }
//};//优化空间版，题目已知课程数量，所以可以不需要可达性的判断，如果没有给定课程数量用自己写的那一版更好
//
//class Solution {
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        unordered_map<int, vector<int>>graph;
//        unordered_map<int, int>visited;
//        for (auto& p : prerequisites) {
//            int pre = p[0], cur = p[1];
//            graph[pre].push_back(cur);
//        }
//        for (int i = 0; i < numCourses; ++i) {
//            if (hasCycleDFS(i, graph, visited)) return false;
//        }
//        return true;
//    }
//
//    bool hasCycleDFS(int pre, unordered_map<int, vector<int>>& graph, unordered_map<int, int>&visited) {
//        if (visited[pre]==2) return false;//说明该节点已经访问过，不需要再次访问
//        if (visited[pre] == 1) return true;//递归路径上再次遇到,，存在环，无法学习完所有课程
//
//        visited[pre] = 1;//标记当前节点为正在访问
//        for (auto& cur : graph[pre]) {//对前置课程的所有后置课程进行DFS递归，判断是否成环
//            if (hasCycleDFS(cur, graph, visited)) return true;//递归地判断这条路径上是否有环
//        }
//        visited[pre] = 2;//遍历完所有路径后，标记这个前置课程所有路径已经被访问过了
//        return false;
//    }
//};
//
//
//
//int main() {
//    vector<vector<int>>prerequisites = { {1,0} };
//    int numCourses = 2;
//    Solution a;
//    cout << a.canFinish(numCourses, prerequisites);
//}