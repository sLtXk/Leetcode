///*
//��һ����n����������ɵ����飬�������Ϊ����ϸ�ݼ��������У����ͨ����ֿ��Ի�õ����ٵ������еĸ���,�������Щ�����С�
//
//˵��:1.ĳ�����е��������Ǵ��������ͨ��ȥ��ĳЩԪ�ص����ƻ�����Ԫ�ص����λ��(��ǰ���ں�)���γɵ������У��Ҹ���������ָ
//��ԭ���е�һ��Ԫ�ر��������һ��Ԫ�ض��γɵ����С�2.�ϸ�ݼ���ָ��������Ԫ��n[i]<n[i-1]�Ļ�����Ϊ�ݼ���������Ծ��ݼ�Ԫ��
//
//��������:
//����һ���ɶ��ŷָ����������ַ��� ��ע:������ȡֵ��Χ1~2147483647
//�������:��������и����������� 
//��ע: 1.������������и�����ĩβ���� 2.ÿ�����һ�������У������������ö��ŷָ�
//
//����:
//���룺7,3,6,2,5,1
//�����
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
//	vector<int>tail;//��¼ÿ�������е���Сֵ
//	vector<vector<int>>substr;//�洢����������
//	substr.push_back({ nums[0] });
//	tail.push_back(nums[0]);
//	for (int i = 1; i < nums.size(); i++) {
//		if (nums[i] >= *max_element(tail.begin(), tail.end())) {//���nums[i]�����е����������е���Сֵ����
//			substr.push_back({ nums[i] });//�½�������
//			tail.push_back(nums[i]);//�½�β��
//		}
//		else {
//			int index = 0, min_tail = INT_MAX;
//			for (int j = 0; j < tail.size(); j++) {
//				if (tail[j] > nums[i] && tail[j] < min_tail) {
//					min_tail = tail[j];
//					index = j;
//				}
//			}//�ҵ��ȵ�ǰ���ִ����С��������β��
//			tail[index] = nums[i];//������������е�β��
//			substr[index].push_back(nums[i]);//�����ҵ����Ǹ���������
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
