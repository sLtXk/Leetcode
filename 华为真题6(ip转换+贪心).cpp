///*
//����Ϊ�������������ַ�滮��Ա����Ҫ���������㲻ͬҵ��������ַ����ÿ��ҵ����Ҫ�ĵ�ַ��ΧΪһ��������[start_ip,end_ip]��ʾ��
//����start_ip����ʼIP��ַ��end_ip����ֹIP��ַ��end_ip���ڵ���start_ip����ͬҵ���IP��ַ�����ص����������Ҫ��ҵ���ַ���󣬰���һ����������
//���������������ַ�滮�������������������ҵ�����󡣵�ҵ��������ͬʱ����IP��ַռ���������ȡ���ҵ��������IP��ַռ��������ͬʱ������IP��Χ˳��
//�Ƚ���ʼIP��ַ����ʼ��ַ��С�����ȡ�
//
//����:
//1.��һ��Ϊҵ�����N����Ч��ΧΪ[1,100]
//2.����N��IP��ַ���䣬����ÿ������ĸ�ʽΪstart_ip end_ip���м��ÿո�ָ���������start_ip��end_ipΪ�Ϸ���IPv4��ַ���ʮ���Ƹ�ʽ����A.B.C.D��
//����A��B��C��D��ȡֵ��ΧΪ[0,255]��
//3.IP��ַ��С�ıȽϣ��ǰ���A��B��C��D��˳����бȽϡ�
//����1
//���룺
//3
//192.168.1.9 192.168.1.12
//192.168.1.1 192.168.1.10
//192.168.1.12 192.168.1.13
//�����
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
//		unsigned int DecimalIP = 0;//��IPת����ʮ������
//		for (char& ch : temp) {
//			if (ch == ' ')//�ո����ǰһ������
//			{
//				interval.push_back(DecimalIP);//����������
//				DecimalIP = 0;//���㣬��ȡ������
//			}
//			else if(ch=='.'){//������ڵ�
//				DecimalIP+=stoi(num) << count * 8;//192.168.1.1�У�192��Ҫ����2^24�η���������24λ��168����16λ�����������count����
//				count--;
//				num.clear();//ÿһ�������һ�������ַ���
//			}
//			else {
//				num += ch;//������ӵ��ַ�����
//			}
//		}
//		interval.push_back(DecimalIP+stoi(num));//��������β,ע��������Ҫ�������һ��num�ֶ�
//		ipRange.push_back(interval);
//	}
//	sort(ipRange.begin(), ipRange.end(), [](const vector<unsigned int>& a, const vector<unsigned int>& b) {
//		if (a[1] != b[1]) return a[1] < b[1];                         // �Ȱ�end����,��ΪҪ�����ܶ��ҵ����������ѡ������ַǰ��
//		if ((a[1] - a[0]) != (b[1] - b[0])) return (a[1] - a[0]) < (b[1] - b[0]); // ���������ַһ�������䳤��С������
//		return a[0] < b[0];                                           // ������ǰ���߾͹��ж���������ˣ�����Ϊ�˷�ֹ��bug��������������ȫ��ͬ�������������һ��
//		});
//
//	vector<pair<unsigned int, unsigned int>>result;
//	unsigned int lastEnd = 0;
//	for (auto& interval : ipRange) {
//		if (result.empty() || interval[0] > lastEnd) {//�����ǰ�����ǰһ����û���ص�
//			result.push_back({ interval[0],interval[1] });//̰�ģ�ѡ���������
//				lastEnd = interval[1];
//		}
//	}
//	auto toIP = [](unsigned int ip) {
//		return to_string((ip >> 24) & 255) + "." +
//			to_string((ip >> 16) & 255) + "." +
//			to_string((ip >> 8) & 255) + "." +
//			to_string(ip & 255);//��1111111��255��λ�룬ȡ��192.168.1.1�ĸ�������
//	};
//
//	for (auto& res : result) {
//		cout << toIP(res.first) << " " << toIP(res.second) << endl;
//	}
//
//}