//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//        public:
//            int maxArea(vector<int>& height) {
//                int res = 0;
//                int n = height.size(), left = 0,right=n-1;
//                while (left < right)
//                {
//                    int s_height = min(height[left], height[right]);
//                    res = max(res, s_height * (right - left));
//                    if (height[left] < height[right]) left++;  
//                    else right--;
//                }
//                return res;
//            }
//};

/*Ϊʲô�����ƶ��ϰ�����һ�ࣿ��Ϊ��������ƶ��ϸߵ���һ��Ļ����ᷢ�����ǵ����ˮ��ֻ���ܼ��ٻ��߲��䣬
��Ϊ���һֱ�ڼ�С������ˮ��ȡ���ڽ϶̵���һ�࣬�����ƶ��ߵ���һ��ֻ�ᵼ�¿�ȼ�С��ͬʱ�϶̵���һ��û��
���߱�ø�С��������������Ҫ����Ĵ�ˮ�������ֻ���ƶ��϶̵���һ�࣬Ѱ�Ҹ��ߵġ��̰塱�����ܵ��������
��С������Ӱ��*/