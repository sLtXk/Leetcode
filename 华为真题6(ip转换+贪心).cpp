///*
//你作为数据中心网络地址规划人员，需要尽可能满足不同业务的网络地址需求。每个业务需要的地址范围为一个闭区间[start_ip,end_ip]表示，
//其中start_ip是起始IP地址，end_ip是终止IP地址，end_ip大于等于start_ip。不同业务的IP地址不能重叠，因此你需要将业务地址需求，按照一定规则排序，
//让数据中心网络地址规划尽可能满足更多数量的业务需求。当业务数量相同时，以IP地址占用最少优先。当业务数量和IP地址占用数量相同时，按照IP范围顺序，
//比较起始IP地址，起始地址最小者优先。
//
//输入:
//1.第一行为业务个数N，有效范围为[1,100]
//2.输入N行IP地址区间，其中每个区间的格式为start_ip end_ip（中间用空格分隔），其中start_ip和end_ip为合法的IPv4地址点分十进制格式，即A.B.C.D，
//其中A、B、C和D的取值范围为[0,255]。
//3.IP地址大小的比较，是按照A、B、C和D的顺序进行比较。
//样例1
//输入：
//3
//192.168.1.9 192.168.1.12
//192.168.1.1 192.168.1.10
//192.168.1.12 192.168.1.13
//输出：
//192.168.1.1 192.168.1.10
//192.168.1.12 192.168.1.13
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
//	int n; cin >>n,cin.ignore(); 
//	vector<vector<unsigned int>>ipRange;
//	for (int i = 0; i < n; i++) {
//		string temp;
//		getline(cin, temp);
//		string num;
//		vector<unsigned int>interval;
//		int count = 3;
//		unsigned int DecimalIP = 0;//将IP转换成十进制数
//		for (char& ch : temp) {
//			if (ch == ' ')//空格代表前一个区间
//			{
//				interval.push_back(DecimalIP);//加入左区间
//				DecimalIP = 0;//置零，提取右区间
//			}
//			else if(ch=='.'){//如果等于点
//				DecimalIP+=stoi(num) << count * 8;//192.168.1.1中，192需要乘以2^24次方，即左移24位，168左移16位，因此这里用count计数
//				count--;
//				num.clear();//每一个点清空一次数字字符串
//			}
//			else {
//				num += ch;//数字添加到字符串中
//			}
//		}
//		interval.push_back(DecimalIP+stoi(num));//加入区间尾,注意这里需要补上最后一个num字段
//		ipRange.push_back(interval);
//	}
//	sort(ipRange.begin(), ipRange.end(), [](const vector<unsigned int>& a, const vector<unsigned int>& b) {
//		if (a[1] != b[1]) return a[1] < b[1];                         // 先按end升序,因为要尽可能多的业务，所以优先选结束地址前的
//		if ((a[1] - a[0]) != (b[1] - b[0])) return (a[1] - a[0]) < (b[1] - b[0]); // 如果结束地址一样，区间长度小的优先
//		return a[0] < b[0];                                           // 理论上前两者就够判断所有情况了，但是为了防止出bug或者两个区间完全相同的情况，补充这一句
//		});
//
//	vector<pair<unsigned int, unsigned int>>result;
//	unsigned int lastEnd = 0;
//	for (auto& interval : ipRange) {
//		if (result.empty() || interval[0] > lastEnd) {//如果当前区间和前一区间没有重叠
//			result.push_back({ interval[0],interval[1] });//贪心，选择这个区间
//				lastEnd = interval[1];
//		}
//	}
//	auto toIP = [](unsigned int ip) {
//		return to_string((ip >> 24) & 255) + "." +
//			to_string((ip >> 16) & 255) + "." +
//			to_string((ip >> 8) & 255) + "." +
//			to_string(ip & 255);//与1111111即255按位与，取出192.168.1.1的各个部分
//	};
//
//	for (auto& res : result) {
//		cout << toIP(res.first) << " " << toIP(res.second) << endl;
//	}
//
//}