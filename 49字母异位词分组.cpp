//#include<iostream>
//#include<unordered_map>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        
//        unordered_map<string, vector<string>>map;
//        for (string&str : strs)
//        {
//            int count[26] = { 0 };//���ڼ�¼ÿ�����ʵ���ĸƵ�ʣ���λ����ĸƵ����ͬ
//            for (char&ch : str)
//            {
//                int tmp = 'ch' - 'a';
//                count[tmp]++;
//            }
//            string tmp = "";//���ڴ洢��ǰ�ַ����İ�����������ĸ����Ϊ��ϣ��ļ�
//            for (int i = 0; i < 26; i++)
//            {
//                while (count[i] != 0)
//                {
//                    tmp.push_back('a' + i);//str����ĸ����tmp��
//                    --i;
//                }
//            }
//            map[tmp].push_back(str);//str�����Ӧ�ô���������У����ϸô���Ķ��������������
//        }
//        vector<vector<string>>res;
//        for (auto &i : map) res.push_back(i.second);//��ÿ�ִ�������������
//        return res;
//    }
//};//ͳ�ƴ�Ƶ�����ݴ�Ƶ�õ�һ������ĸ˳����ַ������ø��ַ�����Ϊ������ĸ��λ�ʵļ���ͬ�����뵽��Ӧ��ֵ��vector��
//
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>>res;
//        unordered_map<string, vector<string>>map;
//        for (string& str : strs) {
//            string temp = str;
//            sort(temp.begin(), temp.end());
//            map[temp].push_back(str);
//        }
//        for (auto& it : map) {
//            res.push_back(it.second);
//        }
//        return res;
//    }
//};//ֱ�����򼴿ɣ���ĸ��λ����������ͬ