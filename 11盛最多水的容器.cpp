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

/*为什么总是移动较矮的那一侧？因为如果我们移动较高的那一侧的话，会发现我们的最大储水量只可能减少或者不变，
因为宽度一直在减小，而储水量取决于较短的那一侧，我们移动高的那一端只会导致宽度减小的同时较短的那一侧没变
或者变得更小，因此我们如果想要更大的储水面积，就只能移动较短的那一侧，寻找更高的“短板”，才能抵消掉宽度
减小带来的影响*/