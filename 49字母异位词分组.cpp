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
//            int count[26] = { 0 };//用于记录每个单词的字母频率，异位词字母频率相同
//            for (char&ch : str)
//            {
//                int tmp = 'ch' - 'a';
//                count[tmp]++;
//            }
//            string tmp = "";//用于存储当前字符串的包含的所有字母，作为哈希表的键
//            for (int i = 0; i < 26; i++)
//            {
//                while (count[i] != 0)
//                {
//                    tmp.push_back('a' + i);//str的字母存入tmp中
//                    --i;
//                }
//            }
//            map[tmp].push_back(str);//str存入对应该词序的数组中，符合该词序的都被加入该数组中
//        }
//        vector<vector<string>>res;
//        for (auto &i : map) res.push_back(i.second);//将每种词序的数组放入结果
//        return res;
//    }
//};//统计词频并根据词频得到一个按字母顺序的字符串，用该字符串作为键，字母异位词的键相同，推入到对应的值即vector中
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
//};//直接排序即可，字母异位词排序结果相同