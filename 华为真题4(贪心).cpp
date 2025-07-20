///*
//假设我们有一系列测试用例，每个测试用例会覆盖测试若干个代码模块。我们用一个二维数组?cases?来表示这些测试用例的覆盖情况，其中cases[i][j]为1表示
//第 i 个测试用例覆盖了第 j 个模块，为0则表示未覆盖。求一个最小的测试用例集合，使得该集合能够覆盖所有代码模块。返回最小集合的大小，如果不存在能够
//覆盖所有代码模块的测试用例集合，则返回?-1。
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
//	int m; cin >> m;
//	int n; cin >> n;//矩阵的行数和列数，m为测试用例的个数，n代表模块的个数
//	vector<vector<int>>cases(m, vector<int>(n));
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			int temp; cin >> temp;
//			cases[i][j] = temp;
//		}
//	}//用例输入
//
//	unordered_set<int>untested;//记录未被测试过的模块
//	for (int i = 0; i < n; i++) {
//		untested.insert(i);
//	}
//	vector<bool>used(m, false);//记录已经被使用过的测试用例
//	int count = 0;//记录使用过的测试用例个数
//
//	while (!untested.empty()) {
//		int optimal_case = -1;//记录剩余案例中覆盖最多模块的测试案例
//		int max_tested = 0;//记录剩余测试案例中覆盖模块数最多的数量
//		for (int i = 0; i < m; i++) {
//			if (used[i]) continue;//跳过已经用过的用例
//			int cur_tested = 0;//当前用例的覆盖模块数量
//			for (int j = 0; j < n; j++) {
//				if (untested.count(j) && cases[i][j] == 1) cur_tested++;//如果当前模块没有被测试过且能被当前用例测试
//
//				if (cur_tested > max_tested) {//如果当前用例覆盖模块数大于目前最大覆盖模块数
//					max_tested = cur_tested;
//					optimal_case = i;//更新当前最佳用例
//				}
//			}
//		}
//		if (max_tested == 0) {//如果遍历完一遍发现剩余用例不能测试任何剩余的模块
//			cout << -1 << endl;//说明无法覆盖所有模块，返回-1
//			return 0;
//		}
//		used[optimal_case] = true;//把当前最佳测试用例标记为使用过
//		count++;//使用的测试用例数+1
//		for (int j = 0; j < n; j++) {
//			if (cases[optimal_case][j] == 1) untested.erase(j);//把当前用例覆盖的测试用例删除
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
