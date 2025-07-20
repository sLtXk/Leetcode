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
//            graph[pre].push_back(cur);//ǰ�ÿγ�ָ����ÿγ�
//            indegree[cur]++;
//        }//��ͼ
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
//        }//�൱�ڲ���ѧϰ���ſγ̣����ѧϰ
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
//            if (hasCycleDFS(i, graph, visited,res)) return {};//�л��ж�Ϊ�޷�ѧϰ
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//
//    bool hasCycleDFS(int pre, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& visited,vector<int>&res) {
//        if (visited[pre] == 2) return false;//˵���ýڵ��Ѿ����ʹ�������Ҫ�ٴη���
//        if (visited[pre] == 1) return true;//�ݹ�·�����ٴ�����,�����ڻ����޷�ѧϰ�����пγ�
//
//        visited[pre] = 1;//��ǵ�ǰ�ڵ�Ϊ���ڷ���
//        for (auto& cur : graph[pre]) {//��ǰ�ÿγ̵����к��ÿγ̽���DFS�ݹ飬�ж��Ƿ�ɻ�
//            if (hasCycleDFS(cur, graph, visited,res)) return true;//�ݹ���ж�����·�����Ƿ��л�
//        }
//        visited[pre] = 2;//����������·���󣬱�����ǰ�ÿγ�����·���Ѿ������ʹ���
//        res.push_back(pre);//ֻ���ڱ����굱ǰ·��ʱ�ż�������,��˴�ʱ�Ľ������˳���Ƿ��ģ��൱��res���鿪ͷ������Ŀγ�
//        return false;
//    }
//};
