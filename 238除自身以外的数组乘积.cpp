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
//    }//��¼�����������������г˻�
//
//    int rightProd = 1;
//    for (int i = n - 1; i >= 0; --i) {
//        answer[i] *= rightProd;
//        rightProd *= nums[i];
//    }//��¼�����������Ҳ�����г˻������������Ľ����˾��Ǵ�
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
//        int leftproduct = 1, rightproduct = 1;//�ֱ��¼��ָ������ĳ˻�������ָ����Ҳ�ĳ˻�
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
///*��i��n-i-1��������ָ�룬����res��������������ͬʱ����ģ���¼�˵�ǰָ���������Ҳ�ĳ˻���
//��i����n-i-1�����Է��������λ��ʱ���Ϳ��Խ����������˻����Ҳ�˻��������õ�����*/