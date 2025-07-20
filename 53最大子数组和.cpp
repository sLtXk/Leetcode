//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution1 {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int preSum = 0, minPreSum = 0, res = INT_MIN;//�ֱ�Ϊ��ǰǰ׺�ͣ���ǰ����Сǰ׺�ͣ��ͽ��
//        for (int& num : nums) {
//            preSum += num;
//            res = max(res, preSum - minPreSum);//����͵��ڵ�ǰ�𰸺͵�ǰǰ׺��-��Сǰ׺�͵����ֵ
//            minPreSum = min(minPreSum, preSum);//������Сǰ׺��
//        }
//        return res;
//    }
//};/*���������������൱���ҵ�һ�����ģ���ǰǰ׺�ͼ�ȥ��ǰ����Сǰ׺�ͣ���������Kadane�㷨��˼��*/
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int curSum = 0, maxSum = INT_MIN;//�Ե�ǰ����Ϊ��β�����������ͣ�������������
//        for (int& num : nums) {
//            curSum = max(num, curSum + num);//�����������ж���ǰ�����������Ƿ�Ϊ�������Ϊ������ֱ��ѡ��nums[i]
//            maxSum = max(maxSum, curSum);
//        }
//        return maxSum;
//    }
//};
///*Kadane�㷨����Ҫô���Ÿɣ�Ҫô��ͷ����
//����ǰ���� vs ȫ�����š�*/
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int curSum = 0, maxSum = INT_MIN;
//        int start = 0, tempStart = 0, end = 0;
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if (curSum + nums[i] < nums[i]) {
//                curSum = nums[i];
//                tempStart = i; // ��ǰԪ�ظ��ţ�������ʼλ��
//            }
//            else {
//                curSum += nums[i];
//            }
//
//            if (curSum > maxSum) {
//                maxSum = curSum;
//                start = tempStart;
//                end = i;
//            }
//        }
//
//        // �����Χ��nums[start..end] ��Ϊ���������
//        cout << "��������鷶Χ: [" << start << ", " << end << "]" << endl;
//        return maxSum;
//    }
//};//��¼��������鷶Χ�İ汾
