///*
//����������һϵ�в���������ÿ�����������Ḳ�ǲ������ɸ�����ģ�顣������һ����ά����?cases?����ʾ��Щ���������ĸ������������cases[i][j]Ϊ1��ʾ
//�� i ���������������˵� j ��ģ�飬Ϊ0���ʾδ���ǡ���һ����С�Ĳ����������ϣ�ʹ�øü����ܹ��������д���ģ�顣������С���ϵĴ�С������������ܹ�
//�������д���ģ��Ĳ����������ϣ��򷵻�?-1��
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
//	int n; cin >> n;//�����������������mΪ���������ĸ�����n����ģ��ĸ���
//	vector<vector<int>>cases(m, vector<int>(n));
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			int temp; cin >> temp;
//			cases[i][j] = temp;
//		}
//	}//��������
//
//	unordered_set<int>untested;//��¼δ�����Թ���ģ��
//	for (int i = 0; i < n; i++) {
//		untested.insert(i);
//	}
//	vector<bool>used(m, false);//��¼�Ѿ���ʹ�ù��Ĳ�������
//	int count = 0;//��¼ʹ�ù��Ĳ�����������
//
//	while (!untested.empty()) {
//		int optimal_case = -1;//��¼ʣ�స���и������ģ��Ĳ��԰���
//		int max_tested = 0;//��¼ʣ����԰����и���ģ������������
//		for (int i = 0; i < m; i++) {
//			if (used[i]) continue;//�����Ѿ��ù�������
//			int cur_tested = 0;//��ǰ�����ĸ���ģ������
//			for (int j = 0; j < n; j++) {
//				if (untested.count(j) && cases[i][j] == 1) cur_tested++;//�����ǰģ��û�б����Թ����ܱ���ǰ��������
//
//				if (cur_tested > max_tested) {//�����ǰ��������ģ��������Ŀǰ��󸲸�ģ����
//					max_tested = cur_tested;
//					optimal_case = i;//���µ�ǰ�������
//				}
//			}
//		}
//		if (max_tested == 0) {//���������һ�鷢��ʣ���������ܲ����κ�ʣ���ģ��
//			cout << -1 << endl;//˵���޷���������ģ�飬����-1
//			return 0;
//		}
//		used[optimal_case] = true;//�ѵ�ǰ��Ѳ����������Ϊʹ�ù�
//		count++;//ʹ�õĲ���������+1
//		for (int j = 0; j < n; j++) {
//			if (cases[optimal_case][j] == 1) untested.erase(j);//�ѵ�ǰ�������ǵĲ�������ɾ��
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
