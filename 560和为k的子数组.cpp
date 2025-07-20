//#include<vector>
//#include<algorithm>
//
//using namespace std;
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int res = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int sum = 0;
//            sum += nums[i];
//            if (sum == k) res++;
//            for (int j = i + 1; j < nums.size(); j++) {
//                sum += nums[j];
//                if (sum == k) res++;
//            }
//        }
//        return res;
//    }
//};//ö�٣����Ӷ�O(n^2)
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int>preSum;//��ϣ����Ϊǰ׺�ͣ�ֵΪ���ִ���
//        preSum[0] = 1;//һ��ʼǰ׺��Ϊ0�ĳ��ִ���Ϊ1�Σ���Ϊ���黹û��ʼ����Ĭ��Ϊ0
//        int res = 0,sum=0;
//        for (int i = 0; i < nums.size(); i++) {
//            sum += nums[i];
//            if (preSum.count(sum - k)) {
//                res += preSum[sum - k];//������ĸ����͵���ǰ׺��Ϊsum-k�ĳ��ִ���
//            }//�����ϣ�������ҵ�ǰ׺��Ϊ��ǰ��sum��ȥk��˵����ǰ׺��sum-k��ǰ׺��Ϊsum���м�����ӳ������Ϊk����Ϊsum-(sum-k)=k
//            preSum[sum]++;//��¼��ǰǰ׺�ͳ��ִ���
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    vector<int>nums = { 1,2,3 };
//    int k = 3;
//    Solution a;
//    cout << a.subarraySum(nums, k);
//}