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
//        unordered_map<int, vector<int>>graph;//����ǰ�ÿγ̣�ֵ��ָ��ĺ��ÿγ����飨һ��ǰ�ÿγ̿����ж��ź��ÿγ̣�
//        unordered_map<int, int>indegree;//�ڵ����ȣ�����һ�ſγ��ж�����ǰ�ÿγ�
//        unordered_set<int>allCourses;//ȫ���γ�
//
//        for (auto& p : prerequisites) {
//            allCourses.insert(p[0]);
//            allCourses.insert(p[1]);//����γ̼�����
//            graph[p[1]].push_back(p[0]);//��ͼ,��һ��������Ȩͼ
//            indegree[p[0]]++;//��ǰ�ÿγ�ָ��ǰ�γ̣���ǰ�γ����+1
//        }//��ʼ��ͼ
//
//        unordered_map<int, bool>reachability;//��¼�ڵ�Ŀɴ���
//        queue<int>q;
//
//        for (const int& course : allCourses) {
//            if (indegree[course] == 0) {
//                q.push(course);
//                reachability[course] = true;
//            }
//        }//������û��ǰ�̿γ̵Ŀ���ӣ����������Ϊ�ɴ׼������BFS
//
//        while (!q.empty()) {
//            int pre_course = q.front(); q.pop();//��ȡ��ǰ�ÿγ�
//            for (int& cur_course : graph[pre_course]) {//������ǰǰ�ÿγ̵����к��ÿγ�
//                indegree[cur_course]--;//��ǰ�γ̵����-1����Ϊ�����Ѿ���������һ��ǰ�ÿγ�
//                if (indegree[cur_course] == 0) {
//                    q.push(cur_course);//�����ǰ�γ�����ǰ�ÿγ̶��������ˣ����Ϳ�����Ϊ�µ�ǰ�ÿγ̼��������
//                    reachability[cur_course] = true;//��ǵ�ǰ�γ�Ϊ�ɴ�,ֻ������ǰ�ÿγ̶��������˲ű��Ϊ�ɴ�
//                }
//            }
//        }//��������+�����������������ǰ�ÿγ������ܴﵽ�Ŀγ̣������������μ�������У�������ǵĿɴ���
//
//        for (const int& course : allCourses) {
//            if (reachability.find(course) == reachability.end()) return false;//��������пγ�����һ�����ɴ�Ŀγ̣�����ѧϰ�����пγ�
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
//        unordered_map<int, vector<int>> graph; // ��ͼ������ǰ�ÿγ̣�ֵ������Ӱ��ĺ��ÿγ��б�
//        vector<int> indegree(numCourses, 0);   // ÿ�ſγ̵����
//
//         //��ʼ��ͼ����ȱ�
//        for (auto& p : prerequisites) {
//            int cur = p[0], pre = p[1];
//            graph[pre].push_back(cur); // ��ǰ�ÿγ�ָ��ǰ�γ�
//            indegree[cur]++;           // ��ǰ�γ���� +1
//        }
//
//        queue<int> q;
//        int finished = 0; // ��¼����ɿγ����������������г��ӵĿγ�����
//
//         //���������Ϊ 0 �Ŀγ���ӣ���û��ǰ��Ҫ��Ŀγ̣�
//        for (int i = 0; i < numCourses; ++i) {
//            if (indegree[i] == 0) {
//                q.push(i);
//            }
//        }//���Ｔʹindegree[i]������Ҳû��ϵ��˵����Щ�γ̲�����ǰ�ÿγ̣�û�г�����prerequisites�����У��䱾����Ǹ�������
//
//         //��������BFS��
//        while (!q.empty()) {
//            int course = q.front(); q.pop();
//            finished++; // �ɹ����һ�ſγ�
//
//            for (int& next : graph[course]) {
//                indegree[next]--;
//                if (indegree[next] == 0) {
//                    q.push(next); // ��ǰ�γ̵�����ǰ�ÿ�����ɣ�����ѧϰ
//                }
//            }
//        }
//
//        // �����ɿγ��� == �ܿγ�����˵���������ȫ���γ�
//        return finished == numCourses;
//    }
//};//�Ż��ռ�棬��Ŀ��֪�γ����������Կ��Բ���Ҫ�ɴ��Ե��жϣ����û�и����γ��������Լ�д����һ�����
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
//        if (visited[pre]==2) return false;//˵���ýڵ��Ѿ����ʹ�������Ҫ�ٴη���
//        if (visited[pre] == 1) return true;//�ݹ�·�����ٴ�����,�����ڻ����޷�ѧϰ�����пγ�
//
//        visited[pre] = 1;//��ǵ�ǰ�ڵ�Ϊ���ڷ���
//        for (auto& cur : graph[pre]) {//��ǰ�ÿγ̵����к��ÿγ̽���DFS�ݹ飬�ж��Ƿ�ɻ�
//            if (hasCycleDFS(cur, graph, visited)) return true;//�ݹ���ж�����·�����Ƿ��л�
//        }
//        visited[pre] = 2;//����������·���󣬱�����ǰ�ÿγ�����·���Ѿ������ʹ���
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