///*
//已知A市运营了N条地铁线路，市民在乘坐地铁时单条线路通票2元，换乘一次加1元。给出N条线路的所有站名列表，
//请帮乘客寻找从出发站到目的站最便宜的地铁换乘方案，并输出票价。每条地铁线路不包含环路，即没有相同站名。
//输入：
//第一行为地铁线路个数N，范围是[1, 1000]； 第2行到第N+1 行：每条线路依次包含的站名，每个站名包含的字
//符个数不超过100，站点个数也不超过100，依次用空格隔开，不同线路中相同的站点名表示是一个换乘站；
//第N+2行，出发站和目的站，用空格隔开。
//输出：
//第一行按照出发站-换乘站(可以是多个)-目的站的格式输出换乘方案的字符串； 第二行输出换乘方案的总票价。
//如果没有任何方案可实现出发站到目的站，只输出一行：NA。
//
//样例：
//输入：
//3
//A B C D F
//C G H
//M I J
//A J
//输出： NA
//*/
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//#include<unordered_set>
//#include<string>
//#include<algorithm>
//#include<sstream>
//#include<queue>
//using namespace std;
//
//int main() {
//	int n; cin >> n; cin.ignore(); //由于cin输入换行符自动停止所以跳过末尾空格
//	unordered_map<string, vector<string>>graph;//图,表示站点之间的相连关系
//	unordered_map<string, vector<int>>station_to_line;//每个站点上有哪几条线路经过（识别换乘站）
//	vector<vector<string>>lines(n);//记录各条线上有哪些站点
//	for (int i = 0; i < n; i++) {
//		string temp;
//		getline(cin, temp);//接收一行的站点信息,由于cin输入空格自动停止所以要接受整行
//		string station;
//		stringstream ss(temp);
//		while (getline(ss, station, ' ')) {
//			lines[i].push_back(station);//第i行代表第i条线路
//			station_to_line[station].push_back(i);//记录站对应线路的映射，和线路所包含的站
//		}//结束一条线路的记录
//		for (int j = 0; j < lines[i].size() - 1; j++) {
//			string a = lines[i][j];
//			string b = lines[i][j + 1];//相邻的两个站点
//			graph[a].push_back(b);
//			graph[b].push_back(a);//两者相互连接
//		}
//	}
//
//    string start, end;
//    cin >> start >> end;
//
//    if (start == end) {
//        cout << start << endl;
//        cout << 2 << endl;
//        return 0;
//    }
//
//    struct State {
//        string station;
//        int line;
//        int cost;
//        vector<string> path;
//        bool operator>(const State& other) const {
//            return cost > other.cost;
//        }
//    };
//
//    priority_queue<State, vector<State>, greater<State>> pq;
//    set<pair<string, int>> visited; // visited[站点][线路]，防止重复走
//
//    // 起点可以从它所在的所有线路开始尝试
//    for (int line : station_to_line[start]) {
//        pq.push({ start, line, 2, {start} });//列表初始化的方式直接构造一个临时类
//        visited.insert({ start, line });
//    }
//
//    while (!pq.empty()) {
//        State cur = pq.top(); pq.pop();
//        string station = cur.station;
//        int line = cur.line;
//
//        for (const string& neighbor : graph[station]) {
//            for (int nextLine : station_to_line[neighbor]) {
//                int newCost = cur.cost;
//                if (nextLine != line) newCost++; // 换乘，加 1 元
//
//                if (visited.count({ neighbor, nextLine })) continue;//如果该节点和线路已经访问过了就跳过
//                visited.insert({ neighbor, nextLine });
//
//                vector<string> newPath = cur.path;
//                newPath.push_back(neighbor);
//
//                if (neighbor == end) {
//                    // 输出路径
//                    string res = start;//先输入起点
//                    for (int i = 0; i < newPath.size() - 1; ++i) {//终点单独处理
//                        const string& s = newPath[i];
//                        if (station_to_line[s].size() > 1) {//我们只选取换乘站输出，其线路必然有两条及以上
//                            res += "-" + s;
//                        }
//                    }
//                    res += "-" + end;//加入终点
//                    cout << res << endl;
//                    cout << newCost << endl;
//                    return 0;
//                }
//
//                pq.push({ neighbor, nextLine, newCost, newPath });
//            }
//        }
//    }
//	cout << "NA" << endl;//此时说明遍历完了连通的部分仍没能到达终点，说明没有方案可以到达，返回NA
//	return 0;
//}
///*
// dijkstra算法适用于有权图，其计算规则如下：
// 1.设定一个出发点，将出发点到其余点的初始距离设为正无穷，从出发点开始遍历
// 2.遍历当前节点的邻居节点，更新出发点到该节点的最小权重，并将其加入最小堆中。
// 3.选择最小堆堆顶，即所有邻居节点中权重最小的那一个，重复过程2。
// 4.遍历结束取决于最终目标，可以为到达某个节点的最小权重或者遍历完整幅图
//
// dijkstra本质上就是带权重的广度有限搜索，在BFS中我们使用邻接表来依次访问节点的各个邻居，用queue来实现
// "广度"的遍历；在dijkstra中，我们使用的是priority_queue来实现带权重的遍历，在这道题中权重就是我们的cost：
// 只有换乘cost才会增加，不换成cost就会减少，我们的目的是找到一个到目的站点cost最小的路径，并返回该路径中的
// 起点，终点和换乘点，并最后返回最小花费，因此可以明确我们的思路如下：
// 1.先建立图，并记录各个站点对应的线路以及每条线路各自有哪些站点；
// 2.特殊情况判断，如果终点和起点相同直接返回
// 3.用dijkstra进行遍历，寻找到终点花费最小的路径，因此我们需要建立最小堆，同时我们还要记录花费和换乘点以及线路，
// 所以我们需要建一个类明确所需的信息：当前站点，当前所在线路，当前花费，以及先前走过的站点（用来回溯路径），利
// 用该四元组作为最小堆中存入的信息，最小堆通过比较两条路线的当前花费来决定先遍历哪条路线
// 4.起点作为最小堆最开始的元素，从起点开始，遍历其邻居节点及邻居节点所在的线路，同时用<站点名，线路>的哈希集合来
// 避免访问已经访问过的路线根据当前线路与邻居节点的线路来判断是否为换乘点计算其花费，再加入到最小堆中进行下一步遍历，
// 下一步遍历选择堆顶即花费最小的节点。
// 5.重复此过程直到找到终点，或者遍历完了一个连通分量都没能找到终点，就输出最后结果
// */