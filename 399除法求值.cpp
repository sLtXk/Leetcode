//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        unordered_map<string, unordered_map<string, double>> graph;//这里的建图方法有点像构建二维数组，只不过这里是二维哈希表
//        /*键为被除数，值为另一个哈希表，存放着所有除数以及对应的商，
//        二维哈希表的键对应节点，二维哈希表的值是一维哈希表的键值对，对应该节点的邻接节点和对应路径权值
//        例如：a/b=3,a/c=4,a/d=6,那么我们的二维哈希表就是:a->{{b->3},{c->4},{d->6}};
//        注意第二维不是键值对pair，而是一个一维的哈希表，其本身就能存储多个键值对
//        */
//        int n = equations.size();
//        for (int i = 0; i < n; i++) {
//            string u = equations[i][0];//字符串u
//            string v = equations[i][1];//字符串v
//            double weight = values[i];//u除以v的值
//            graph[u][v] = weight;//  被除数u->v的权重，可以视为节点u->v
//            graph[v][u] = 1.0 / weight;//  反过来也一样，因为除法可以转换成乘以除数的倒数
//        }
//        //建立被除数和除数的图，可以视为一个有向图，边的权重为商，除数和被除数视为两个节点，可以互为起点和终点
//
//        int m = queries.size();
//        vector<double> results(m, -1.0);//没有答案默认-1.0
//
//        for (int i = 0; i < m; i++) {//遍历所有问题
//            string start = queries[i][0];//当前问题中的被除数，可以看作目标路径的起点
//            string target = queries[i][1];//当前问题中的除数,可以看作目标路径的终点
//            if (!graph.count(start) || !graph.count(target)) {
//                continue;
//            }//如果图中找不到除数或者被除数其中一个，说明没有答案，直接跳过
//            if (start == target) {
//                results[i] = 1.0;
//                continue;
//            }//如果除数被除数相等，答案就是1.0
//
//            //开始搜索邻接节点
//            queue<pair<string, double>> q;//队列中存放当前到达的节点以及从起点到达该节点的权值积
//            unordered_map<string, bool> visited;//记录当前节点是否被访问过
//            q.push({ start, 1.0 });//路径从start开始，对应的商为1.0
//            visited[start] = true;//当前节点已经访问过
//
//            while (!q.empty()) {
//                string curr = q.front().first;//当前节点
//                double currVal = q.front().second;//当前的商，即从start开始到curr这条路径的总权值
//                q.pop();
//                if (curr == target) {//如果当前节点就是我们想要的终点
//                    results[i] = currVal;//记录当前问题的结果
//                    break;
//                }
//                for (auto neighbor : graph[curr]) {
//                    /*如果当前节点不是目标节点，我们就遍历当前节点的邻居，graph[curr]为一维哈希表，
//                    对应当前被除数所有可能的除数和对应的商，在图中就是所有邻接节点以及对应的权值*/
//                    string next = neighbor.first;//下一个可能的节点（邻居节点）
//                    double nextVal = neighbor.second;//对应的商
//                    if (!visited[next]) {//如果下一节点我们没有访问过
//                        visited[next] = true;//记为访问过
//                        q.push({ next, currVal * nextVal });//将邻居节点和对应到达该邻居节点的权值积加入队列中
//                    }
//                    //访问过的邻居不需要再次访问
//                }
//            }
//            /*
//                举个简单的例子，比如我们从equation中得到a/b=3,b/c=2,a/d=3,然后query的问题是a/c是多少
//                在我们建立了有向图后，这个问题转换成从a->c的路径权值的积是多少？c就是终点，a就是起点
//                因此我们需要以a为起点开始进行广度优先搜索，首先先搜索a的邻居b和d，b和d都不是我们的target
//                终点c。因此我们先将b和d以及a->b,a->c的权值积加入队列，a->b=a->a->b,所以这里就是为什么我们
//                将队列一开始推入{ start, 1.0 }，它代表着a->a=a/a=1.0，这样我们后续就可以用1.0*a/b得到a->b
//                的权值。之后我们开始在遍历b的邻居，看b能不能到达c，遍历完b的邻居后遍历d的邻居，观察d能否
//                到达c。这就是广度优先搜索，我们每一次都寻找当前节点的所有邻居并加入队列，然后在提取出队列中
//                的每一个邻居，看邻居的邻居能否到达目的地。
//
//                而我们将a/b=3转换成a->b的路径权值是3，同时也要记录反向的路径b/a=b->a权值是1/3，这样我们就可以
//                将问题转换成找到一条起点终点固定的目的路径，并计算这条路径上各路径权值的乘积。
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
//    // 建图函数
//    unordered_map<string, unordered_map<string, double>> graph;
//
//    // DFS函数：从curr出发到target，如果找到就把路径上的乘积赋值给result，返回true
//    bool dfs(string curr, string target, unordered_map<string, bool>& visited, double& result, double pathVal) {
//        if (curr == target) {
//            result = pathVal;
//            return true;
//        }
//
//        visited[curr] = true;
//
//        for (auto& neighbor : graph[curr]) {//对每一个邻居依次进行dfs
//            string next = neighbor.first;
//            double val = neighbor.second;
//            if (!visited[next]) {
//                if (dfs(next, target, visited, result, pathVal * val)) {
//                    return true;
//                }
//            }
//        }//深度优先搜索，如果邻居节点没访问过，就对应邻居节点进行dfs
//
//        return false;
//    }
//
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        // Step 1: 建图
//        for (int i = 0; i < equations.size(); ++i) {
//            string a = equations[i][0];
//            string b = equations[i][1];
//            double val = values[i];
//            graph[a][b] = val;
//            graph[b][a] = 1.0 / val;
//        }
//
//        // Step 2: 查询
//        vector<double> res;
//        for (auto& query : queries) {
//            string start = query[0];
//            string end = query[1];
//
//            if (!graph.count(start) || !graph.count(end)) {
//                res.push_back(-1.0);
//                continue;
//            }//找不到问题的被除数或者除数，则答案是默认的-1
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