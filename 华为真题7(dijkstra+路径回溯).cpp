///*
//大湾区某城市地铁线路非常密集，乘客很难一眼看出选择哪条线路乘坐比较合适，为了解决这个问题，
//地铁公司希望你开发一个程序帮助乘客挑选合适的乘坐线路，使得乘坐时间最短，地铁公司可以提供
//的数据是各相邻站点之间的乘坐时间。
//输入：
//第一行:N，站点总数,3<=N<=20.
//第二行:乘客 的出发和到达站点。
//第三行起:相邻站点之间的乘坐时间，每对站点一行，站点名称是单个小写字母，站点名一定包括出发和到达站点，输入保证只有一个唯一解;
//结束行:0000
//
//输出：
//耗时最短的线路
//示例：
//输入：
//12
//a e
//a b 2
//b c 2
//c d 2
//d e 2
//f b 3
//b g 3
//g h 2
//h i 3
//j h 2
//h e 3
//e k 2
//k i 4
//0000
//
//输出：
//a b c d e
//*/
//
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
//	int n;
//	cin >> n;
//	char start, dest;
//	cin >> start >> dest;
//	cin.ignore();
//	unordered_map<char, vector<pair<char, int>>>graph;//分别是站点，相邻站点和对应的时长
//	string line;
//	while (getline(cin, line)) {
//		if (line == "0000") break;
//		stringstream ss(line);
//		char station, neighbor;
//		int time;
//		ss >> station >> neighbor >> time;
//		graph[station].push_back({ neighbor,time });//建图
//		graph[neighbor].push_back({ neighbor,time });
//	}
//
//	unordered_map<char, int>time;//记录到达各站点的最短时间
//	unordered_map<char, char>prev;//记录当前节点的前一节点
//	for (auto& p : graph) {
//		time[p.first] = INT_MAX;//不可达节点均为正无穷
//	}
//	time[start] = 0;//到自己的时间是0
//
//	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>>pq;//根据时间排序
//	pq.push({ 0,start });
//	while (!pq.empty()) {
//		auto p = pq.top(); pq.pop();//取出堆顶，是堆中到达时间最短的节点
//		int t = p.first;//原来到该站点的时间
//		char station = p.second;//当前站点
//		if (t > time[station]) continue;//如果已经有时间更短的路径了，舍弃旧路径
//		for (auto neighbor : graph[station]) {//遍历当前站点的邻居
//			char cur_neighbor = neighbor.first;
//			int cur_t = neighbor.second;
//			if (time[cur_neighbor] > time[station] + cur_t) {//到达当前邻居存在更短的路径
//				time[cur_neighbor] = time[station] + cur_t;//更新更短路径
//				prev[cur_neighbor] = station;//更新到达邻居最短路径中的前一站点
//				pq.push({ time[cur_neighbor],cur_neighbor });//加入优先队列
//			}
//		}
//	}
//	vector<char>path;
//	for (char ch = dest; ch != start; ch = prev[ch]) {
//		path.push_back(ch);
//	}
//	path.push_back(start);
//	for (int i = path.size() - 1; i > 0; i--) {
//		cout << path[i] << ' ';
//	}
//	cout << path[0] << endl;
//}