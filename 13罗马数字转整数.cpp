//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//
//class Solution {
//public:
//    int romanToInt(string s) {
//        unordered_map<char, int>map =
//        {
//            {'I',1},
//            {'V',5},
//            {'X',10},
//            {'L',50},
//            {'C',100},
//            {'D',500},
//            {'M',1000},
//        };
//        int res = 0;
//        for (int i=0;i<s.size()-1;i++)
//        {
//            if (map[s[i]] < map[s[i + 1]]) res -= map[s[i]];
//            else res += map[s[i]];   
//        }
//        res += map[s.back()];
//        return res;
//    }
//};