///*
//输入：
//第一行为记录的版本迭代关系个数N，范围是[1，100000];第二行到第N+1行：每行包含两个字符串，第一个字符串为当前版本，
//第二个字符串为前序版本，用空格隔开。字符串包含字符个数为[1，100]，没有前序版本的第二个字符串固定为NA。
//
//输出：
//所有迭代次数最多的补丁版本号字符串列表，多个版本号以字典序排序排列，用空格隔开。
//
//样例1：
//6  
//CN0001 BF0001  
//BF0001 AZ0001  
//AZ0001 NA
//BF0010 AZ0001
//AWOO01 NA
//BF0011 AZ0001
//
//输出：CN0001
//
//解释：AZ0001和AWV0001没有前序版本，各选代了0次; 
//BF0001，BF0010和BF0011的前序版本为AZ0001，各选代了1次;
//CN0010的前序版本为BF0001，BF0001的前序版本为AZ0001，选代了2次。
//根据要求选择迭代次数最多的补丁版本，因此输出CN0010。*/
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//#include<string>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//int main() {
//	int n; cin >> n;
//	unordered_map<string, vector<string>>graph;//键是前继版本，值是其所有后继版本
//	unordered_map<string, int>indegree;//记录每个版本的入度
//	set<string>all_ver;//记录全部版本
//	for (int i = 0; i < n; i++) {
//		string curr_ver, pre_ver;//当前版本和其前继版本
//		cin >> curr_ver >> pre_ver;
//		all_ver.insert(curr_ver);//先将当前版本插入全部版本中
//		if (pre_ver != "NA") {//如果有前继版本
//			all_ver.insert(pre_ver);
//			graph[pre_ver].push_back(curr_ver);//连接有向图，前继版本指向当前版本
//			indegree[curr_ver]++;//当前版本的入度+1
//		}
//		else indegree[curr_ver] = 0;//否则当前版本入度为0，因为没有前继版本
//	}//图的构建
//
//	unordered_map<string, int>depth;//记录每个字符串的对应深度
//	queue<string>q;//用于BFS
//
//	for (auto& version : all_ver) {
//		if (indegree[version] == 0) { //如果一个版本入度为0，说明它是初始版本
//			q.push(version);
//			depth[version] = 0;
//		}
//	}//为所有初始版本设定度为0，并且将所有初始版本入队（其实是将所有入度为0的版本入队）
//
//	//拓扑遍历+BFS
//	while (!q.empty()) {
//		string prev = q.front(); q.pop();
//		for (string& cur : graph[prev]) {//遍历所有初始版本的后继版本，cur即为当前版本，prev是其初始版本（前继版本）
//			depth[cur] = max(depth[prev]+1, depth[cur]);
//			//当前版本的深度为前继版本的深度+1与本身的深度取最大值（一般来说depth[curr]还没有被创建，会被直接初始化为0）
//			indegree[cur]--;//遍历过一个前继节点，当前节点的入度减一
//			if (indegree[cur] == 0) q.push(cur);
//			//将入度为0的版本入队，意味着该版本在之后的遍历中只会作为前继版本，因为该版本的前继版本已经遍历完了（即入度为0了）
//		}
//	}
//
//	int max_depth = 0;
//	for (auto& p : depth) {
//		 max_depth =max(max_depth,p.second);
//	}//记录depth中最深的深度
//
//	vector<string>res;//记录结果
//	for (auto& p : depth) {
//		if (p.second == max_depth) res.push_back(p.first);//将对应最深的字符串存入结果数组中
//	}
//	sort(res.begin(), res.end());
//	for (int i = 0; i < res.size();i++) {
//		cout << res[i];
//		if (i != res.size() - 1) cout << " ";
//	}
//	cout << endl;
//}