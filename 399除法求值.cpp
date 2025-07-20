//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        unordered_map<string, unordered_map<string, double>> graph;//����Ľ�ͼ�����е��񹹽���ά���飬ֻ���������Ƕ�ά��ϣ��
//        /*��Ϊ��������ֵΪ��һ����ϣ����������г����Լ���Ӧ���̣�
//        ��ά��ϣ��ļ���Ӧ�ڵ㣬��ά��ϣ���ֵ��һά��ϣ��ļ�ֵ�ԣ���Ӧ�ýڵ���ڽӽڵ�Ͷ�Ӧ·��Ȩֵ
//        ���磺a/b=3,a/c=4,a/d=6,��ô���ǵĶ�ά��ϣ�����:a->{{b->3},{c->4},{d->6}};
//        ע��ڶ�ά���Ǽ�ֵ��pair������һ��һά�Ĺ�ϣ���䱾����ܴ洢�����ֵ��
//        */
//        int n = equations.size();
//        for (int i = 0; i < n; i++) {
//            string u = equations[i][0];//�ַ���u
//            string v = equations[i][1];//�ַ���v
//            double weight = values[i];//u����v��ֵ
//            graph[u][v] = weight;//  ������u->v��Ȩ�أ�������Ϊ�ڵ�u->v
//            graph[v][u] = 1.0 / weight;//  ������Ҳһ������Ϊ��������ת���ɳ��Գ����ĵ���
//        }
//        //�����������ͳ�����ͼ��������Ϊһ������ͼ���ߵ�Ȩ��Ϊ�̣������ͱ�������Ϊ�����ڵ㣬���Ի�Ϊ�����յ�
//
//        int m = queries.size();
//        vector<double> results(m, -1.0);//û�д�Ĭ��-1.0
//
//        for (int i = 0; i < m; i++) {//������������
//            string start = queries[i][0];//��ǰ�����еı����������Կ���Ŀ��·�������
//            string target = queries[i][1];//��ǰ�����еĳ���,���Կ���Ŀ��·�����յ�
//            if (!graph.count(start) || !graph.count(target)) {
//                continue;
//            }//���ͼ���Ҳ����������߱���������һ����˵��û�д𰸣�ֱ������
//            if (start == target) {
//                results[i] = 1.0;
//                continue;
//            }//���������������ȣ��𰸾���1.0
//
//            //��ʼ�����ڽӽڵ�
//            queue<pair<string, double>> q;//�����д�ŵ�ǰ����Ľڵ��Լ�����㵽��ýڵ��Ȩֵ��
//            unordered_map<string, bool> visited;//��¼��ǰ�ڵ��Ƿ񱻷��ʹ�
//            q.push({ start, 1.0 });//·����start��ʼ����Ӧ����Ϊ1.0
//            visited[start] = true;//��ǰ�ڵ��Ѿ����ʹ�
//
//            while (!q.empty()) {
//                string curr = q.front().first;//��ǰ�ڵ�
//                double currVal = q.front().second;//��ǰ���̣�����start��ʼ��curr����·������Ȩֵ
//                q.pop();
//                if (curr == target) {//�����ǰ�ڵ����������Ҫ���յ�
//                    results[i] = currVal;//��¼��ǰ����Ľ��
//                    break;
//                }
//                for (auto neighbor : graph[curr]) {
//                    /*�����ǰ�ڵ㲻��Ŀ��ڵ㣬���Ǿͱ�����ǰ�ڵ���ھӣ�graph[curr]Ϊһά��ϣ��
//                    ��Ӧ��ǰ���������п��ܵĳ����Ͷ�Ӧ���̣���ͼ�о��������ڽӽڵ��Լ���Ӧ��Ȩֵ*/
//                    string next = neighbor.first;//��һ�����ܵĽڵ㣨�ھӽڵ㣩
//                    double nextVal = neighbor.second;//��Ӧ����
//                    if (!visited[next]) {//�����һ�ڵ�����û�з��ʹ�
//                        visited[next] = true;//��Ϊ���ʹ�
//                        q.push({ next, currVal * nextVal });//���ھӽڵ�Ͷ�Ӧ������ھӽڵ��Ȩֵ�����������
//                    }
//                    //���ʹ����ھӲ���Ҫ�ٴη���
//                }
//            }
//            /*
//                �ٸ��򵥵����ӣ��������Ǵ�equation�еõ�a/b=3,b/c=2,a/d=3,Ȼ��query��������a/c�Ƕ���
//                �����ǽ���������ͼ���������ת���ɴ�a->c��·��Ȩֵ�Ļ��Ƕ��٣�c�����յ㣬a�������
//                ���������Ҫ��aΪ��㿪ʼ���й����������������������a���ھ�b��d��b��d���������ǵ�target
//                �յ�c����������Ƚ�b��d�Լ�a->b,a->c��Ȩֵ��������У�a->b=a->a->b,�����������Ϊʲô����
//                ������һ��ʼ����{ start, 1.0 }����������a->a=a/a=1.0���������Ǻ����Ϳ�����1.0*a/b�õ�a->b
//                ��Ȩֵ��֮�����ǿ�ʼ�ڱ���b���ھӣ���b�ܲ��ܵ���c��������b���ھӺ����d���ھӣ��۲�d�ܷ�
//                ����c������ǹ����������������ÿһ�ζ�Ѱ�ҵ�ǰ�ڵ�������ھӲ�������У�Ȼ������ȡ��������
//                ��ÿһ���ھӣ����ھӵ��ھ��ܷ񵽴�Ŀ�ĵء�
//
//                �����ǽ�a/b=3ת����a->b��·��Ȩֵ��3��ͬʱҲҪ��¼�����·��b/a=b->aȨֵ��1/3���������ǾͿ���
//                ������ת�����ҵ�һ������յ�̶���Ŀ��·��������������·���ϸ�·��Ȩֵ�ĳ˻���
//            */
//        }
//        return results;
//    }//BFS
//};
//
//
//
//class Solution {
//public:
//    // ��ͼ����
//    unordered_map<string, unordered_map<string, double>> graph;
//
//    // DFS��������curr������target������ҵ��Ͱ�·���ϵĳ˻���ֵ��result������true
//    bool dfs(string curr, string target, unordered_map<string, bool>& visited, double& result, double pathVal) {
//        if (curr == target) {
//            result = pathVal;
//            return true;
//        }
//
//        visited[curr] = true;
//
//        for (auto& neighbor : graph[curr]) {//��ÿһ���ھ����ν���dfs
//            string next = neighbor.first;
//            double val = neighbor.second;
//            if (!visited[next]) {
//                if (dfs(next, target, visited, result, pathVal * val)) {
//                    return true;
//                }
//            }
//        }//�����������������ھӽڵ�û���ʹ����Ͷ�Ӧ�ھӽڵ����dfs
//
//        return false;
//    }
//
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        // Step 1: ��ͼ
//        for (int i = 0; i < equations.size(); ++i) {
//            string a = equations[i][0];
//            string b = equations[i][1];
//            double val = values[i];
//            graph[a][b] = val;
//            graph[b][a] = 1.0 / val;
//        }
//
//        // Step 2: ��ѯ
//        vector<double> res;
//        for (auto& query : queries) {
//            string start = query[0];
//            string end = query[1];
//
//            if (!graph.count(start) || !graph.count(end)) {
//                res.push_back(-1.0);
//                continue;
//            }//�Ҳ�������ı��������߳����������Ĭ�ϵ�-1
//
//            if (start == end) {
//                res.push_back(1.0);
//                continue;
//            }
//
//            unordered_map<string, bool> visited;
//            double result = -1.0;
//            dfs(start, end, visited, result, 1.0);
//            res.push_back(result);
//        }
//
//        return res;
//    }
//};//DFS