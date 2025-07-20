///*
//编写一个程序为某云服务计算客户话单，输入为某云服务的计费日志和各种计费因子的计费单价的列表，计费日志内容包含时间戳、客户标识、计费因子、
//计费时长4个字段。日志中如果同一客户同一计费因子在相同时间戳上报多次话单只能计费一次，选先上报的日志计费。计算每个客户的话单总费用。
//
//输入:
//第1行表示计费日志的条数n，是一个正整数，范围是1<=n<=1000。
//第2到n+1行表示云服务的计费日志，共4列，第1列表示时间戳(是一个数字字符串，长度为10) 、
//第2列表示客户标识(是一个字符串，长度为1-16)，第3列表示计费因子 (是一个字符串，长度为1-16，计费因子查不到时认为计费因子单价是0），
//第4列表示计费时长时长（范围为0-100，当计费时长不在范围内要认为是计费日志有问题，当成计费为0处理)，这4个字段使用迈号分隔.
//
//第n+2行表示计费因子的数量m，m是一个正整数，范围是1<=m<=100第n+3到n+3+m行表示各种计费因子的计费单价的列表，
//该表有2列,第1列表示计费因子 (是一个字符串，长度为1-16)，第2列表示单价(是一个正整数，范围为1~100)，这2个字段使用逗号分隔。
//
//输出：每个客户的话单总费用,共2列，第1列表示客户名，第2列表示话单费用，2列用逗号分割，输出按客户标识字典序升序排序
//
//样例：
//输入：
//5
//1627845600,client1,factorA,10
//1627845605,client2,factorB,15
//1627845610,client1,factorA,5
//1627845610,client1,factorB,8
//1627845620,client2,factorB,20
//2
//factorA,5
//factorB,7
//
//输出：
//client1,131
//client2，245
//*/
//
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <tuple>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<string>log_temp(4);//临时日志，记录每一行对应时间戳，客户，计费因子，计费时长
//    unordered_set<string>seenlog;// 同一客户同一计费因子在相同时间戳上报多次话单只能计费一次，用于判断是否出现过同一时间戳、客户、计费因子的记录（去重）
//    map<pair<string, string>, int>clientFactorDurationMap;//键为客户名和计费因子，值为对应的时长,这里只能用map因为哈希表不能用pair作为键的参数
//
//    for (int i = 0; i < n; i++) {
//        string temp; cin >> temp;
//        string token;
//        stringstream ss(temp);
//        int index = 0;
//        while (getline(ss, token, ',')) {//ss分割字符串
//            log_temp[index] = token;//将日志中各条存入临时日志
//            index++;
//        }
//        string time = log_temp[0];
//        string client = log_temp[1];
//        string factor = log_temp[2];
//        string duration = log_temp[3];
//
//        string key = time + client + factor;//用于去重
//        if (seenlog.count(key)) continue;//如果出现同一客户同一计费因子在相同时间戳上，跳过，只取第一次的
//        seenlog.insert(key);
//        int dur = stoi(duration);//转换成整型
//        if (dur < 0 || dur>100) continue;
//        clientFactorDurationMap[{client, factor}] += dur;//记录客户，计费因子和对应的时长
//    }
//
//    int m; cin >> m;//因子数量
//    vector<string>factor_temp(2);//用于存放factor和对应的单价的临时字符串
//    unordered_map<string, int>price;//记录因子对应时长的单价
//    for (int i = 0; i < m; i++) {
//        string temp;
//        cin >> temp;
//        string token;
//        stringstream ss(temp);
//        int index = 0;
//        while (getline(ss, token, ',')) {
//            factor_temp[index] = token;
//            index++;
//        }
//        string factor = factor_temp[0];
//        string strval = factor_temp[1];
//        int val = stoi(strval);//将价格转化为整数
//        price[factor] = val;
//    }
//    map<string, int>res;//记录客户对应话费值
//    for (auto& p : clientFactorDurationMap) {
//        string client = p.first.first;
//        string factor = p.first.second;
//        int duration = p.second;
//        if (price.count(factor)) res[client] += duration * price[factor];//只有找的到该计费因子才计算花费，花费就等于时长乘以单价
//    }
//
//    for (auto& p : res) {
//        cout << p.first << ',' << p.second << endl;
//    }
//    return 0;
//}
//
//
