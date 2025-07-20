///*
//给一个由n个正整数组成的数组，将它拆分为多个严格递减的子序列，输出通过拆分可以获得的最少的子序列的个数,并输出这些子序列。
//
//说明:1.某个序列的子序列是从最初序列通过去除某些元素但不破坏余下元素的相对位置(在前或在后)而形成的新序列，且该子序列是指
//从原序列第一个元素遍历到最后一个元素而形成的序列。2.严格递减，指的是数组元素n[i]<n[i-1]的话，即为递减，不能跳跃算递减元素
//
//输入描述:
//输入一个由逗号分隔的正整数字符串 备注:正整数取值范围1~2147483647
//输出描述:输出子序列个数和子序列 
//备注: 1.首行输出子序列个数，末尾换行 2.每行输出一个子序列，序列内数字用逗号分隔
//
//样例:
//输入：7,3,6,2,5,1
//输出：
//2
//7,3,2,1
//6,5
//*/
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//#include<string>
//#include<algorithm>
//#include<sstream>
//#include<queue>
//using namespace std;
//
//int main() {
//	string str;
//	cin >> str;
//	string token;
//	vector<int>nums;
//	stringstream ss(str);
//	while (getline(ss, token, ',')) {
//		nums.push_back(stoi(token));
//	}
//
//	int n = nums.size();
//	vector<int>tail;//记录每个子序列的最小值
//	vector<vector<int>>substr;//存储各个子序列
//	substr.push_back({ nums[0] });
//	tail.push_back(nums[0]);
//	for (int i = 1; i < nums.size(); i++) {
//		if (nums[i] >= *max_element(tail.begin(), tail.end())) {//如果nums[i]比已有的所有子序列的最小值都大
//			substr.push_back({ nums[i] });//新建子序列
//			tail.push_back(nums[i]);//新建尾部
//		}
//		else {
//			int index = 0, min_tail = INT_MAX;
//			for (int j = 0; j < tail.size(); j++) {
//				if (tail[j] > nums[i] && tail[j] < min_tail) {
//					min_tail = tail[j];
//					index = j;
//				}
//			}//找到比当前数字大的最小的子序列尾部
//			tail[index] = nums[i];//更新这个子序列的尾部
//			substr[index].push_back(nums[i]);//插入找到的那个子序列中
//		}
//	}
//	cout << substr.size() << endl;
//	for (int i = 0; i < substr.size(); i++) {
//		string temp = "";
//		for (int j = 0; j < substr[i].size(); j++) {
//			if (j != substr[i].size() - 1) {
//				temp+=to_string(substr[i][j]);
//				temp.push_back(',');
//			}
//			else temp += to_string(substr[i][j]);
//		}
//		cout << temp << endl;
//	}
//}
