///*
//��дһ������Ϊĳ�Ʒ������ͻ�����������Ϊĳ�Ʒ���ļƷ���־�͸��ּƷ����ӵļƷѵ��۵��б��Ʒ���־���ݰ���ʱ������ͻ���ʶ���Ʒ����ӡ�
//�Ʒ�ʱ��4���ֶΡ���־�����ͬһ�ͻ�ͬһ�Ʒ���������ͬʱ����ϱ���λ���ֻ�ܼƷ�һ�Σ�ѡ���ϱ�����־�Ʒѡ�����ÿ���ͻ��Ļ����ܷ��á�
//
//����:
//��1�б�ʾ�Ʒ���־������n����һ������������Χ��1<=n<=1000��
//��2��n+1�б�ʾ�Ʒ���ļƷ���־����4�У���1�б�ʾʱ���(��һ�������ַ���������Ϊ10) ��
//��2�б�ʾ�ͻ���ʶ(��һ���ַ���������Ϊ1-16)����3�б�ʾ�Ʒ����� (��һ���ַ���������Ϊ1-16���Ʒ����Ӳ鲻��ʱ��Ϊ�Ʒ����ӵ�����0����
//��4�б�ʾ�Ʒ�ʱ��ʱ������ΧΪ0-100�����Ʒ�ʱ�����ڷ�Χ��Ҫ��Ϊ�ǼƷ���־�����⣬���ɼƷ�Ϊ0����)����4���ֶ�ʹ�����ŷָ�.
//
//��n+2�б�ʾ�Ʒ����ӵ�����m��m��һ������������Χ��1<=m<=100��n+3��n+3+m�б�ʾ���ּƷ����ӵļƷѵ��۵��б�
//�ñ���2��,��1�б�ʾ�Ʒ����� (��һ���ַ���������Ϊ1-16)����2�б�ʾ����(��һ������������ΧΪ1~100)����2���ֶ�ʹ�ö��ŷָ���
//
//�����ÿ���ͻ��Ļ����ܷ���,��2�У���1�б�ʾ�ͻ�������2�б�ʾ�������ã�2���ö��ŷָ������ͻ���ʶ�ֵ�����������
//
//������
//���룺
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
//�����
//client1,131
//client2��245
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
//    vector<string>log_temp(4);//��ʱ��־����¼ÿһ�ж�Ӧʱ������ͻ����Ʒ����ӣ��Ʒ�ʱ��
//    unordered_set<string>seenlog;// ͬһ�ͻ�ͬһ�Ʒ���������ͬʱ����ϱ���λ���ֻ�ܼƷ�һ�Σ������ж��Ƿ���ֹ�ͬһʱ������ͻ����Ʒ����ӵļ�¼��ȥ�أ�
//    map<pair<string, string>, int>clientFactorDurationMap;//��Ϊ�ͻ����ͼƷ����ӣ�ֵΪ��Ӧ��ʱ��,����ֻ����map��Ϊ��ϣ������pair��Ϊ���Ĳ���
//
//    for (int i = 0; i < n; i++) {
//        string temp; cin >> temp;
//        string token;
//        stringstream ss(temp);
//        int index = 0;
//        while (getline(ss, token, ',')) {//ss�ָ��ַ���
//            log_temp[index] = token;//����־�и���������ʱ��־
//            index++;
//        }
//        string time = log_temp[0];
//        string client = log_temp[1];
//        string factor = log_temp[2];
//        string duration = log_temp[3];
//
//        string key = time + client + factor;//����ȥ��
//        if (seenlog.count(key)) continue;//�������ͬһ�ͻ�ͬһ�Ʒ���������ͬʱ����ϣ�������ֻȡ��һ�ε�
//        seenlog.insert(key);
//        int dur = stoi(duration);//ת��������
//        if (dur < 0 || dur>100) continue;
//        clientFactorDurationMap[{client, factor}] += dur;//��¼�ͻ����Ʒ����ӺͶ�Ӧ��ʱ��
//    }
//
//    int m; cin >> m;//��������
//    vector<string>factor_temp(2);//���ڴ��factor�Ͷ�Ӧ�ĵ��۵���ʱ�ַ���
//    unordered_map<string, int>price;//��¼���Ӷ�Ӧʱ���ĵ���
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
//        int val = stoi(strval);//���۸�ת��Ϊ����
//        price[factor] = val;
//    }
//    map<string, int>res;//��¼�ͻ���Ӧ����ֵ
//    for (auto& p : clientFactorDurationMap) {
//        string client = p.first.first;
//        string factor = p.first.second;
//        int duration = p.second;
//        if (price.count(factor)) res[client] += duration * price[factor];//ֻ���ҵĵ��üƷ����Ӳż��㻨�ѣ����Ѿ͵���ʱ�����Ե���
//    }
//
//    for (auto& p : res) {
//        cout << p.first << ',' << p.second << endl;
//    }
//    return 0;
//}
//
//
