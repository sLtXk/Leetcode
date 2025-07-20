//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//vector<int> productExceptSelf(vector<int>& nums) {
//    int n = nums.size();
//    vector<int> answer(n, 1);
//
//    int leftProd = 1;
//    for (int i = 0; i < n; ++i) {
//        answer[i] = leftProd;
//        leftProd *= nums[i];
//    }//记录数组中数字左侧的所有乘积
//
//    int rightProd = 1;
//    for (int i = n - 1; i >= 0; --i) {
//        answer[i] *= rightProd;
//        rightProd *= nums[i];
//    }//记录数组中数字右侧的所有乘积，将其与左侧的结果相乘就是答案
//
//    return answer;
//}
//
//
//
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int n = nums.size();
//        int leftproduct = 1, rightproduct = 1;//分别记录左指针的左侧的乘积，和右指针的右侧的乘积
//        vector<int>res(n, 1);
//        for (int i = 0; i < n; i++) {
//            res[i] *= leftproduct;
//            leftproduct *= nums[i];
//            res[n - i - 1] *= rightproduct;
//            rightproduct *= nums[n - i - 1];
//        }
//        return res;
//    }
//};
///*用i和n-i-1代表左右指针，由于res数组是左右两边同时处理的，记录了当前指针左侧或者右侧的乘积，
//当i或者n-i-1处理到对方处理过的位置时，就可以将该数字左侧乘积和右侧乘积乘起来得到答案了*/