//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size();
//        vector<int>sum(n + 1, 0);//��¼ǰ׺�ͣ�sum[n]��¼numsǰn��Ԫ��,sum[0]������û��Ԫ��������0
//        for (int i = 1; i <= n; i++)
//        {
//            sum[i] = sum[i - 1] + nums[i - 1];
//        }
//        int ans = n + 1;
//        for (int i = 0; i < n; i++)//i������Ϊn����Ϊsum[n]�Ѿ�����������ǰ׺���ˣ��Ҳ���sumj��sumn����
//        {
//            int sumj = target + sum[i];
//            auto it = lower_bound(sum.begin(), sum.end(), sumj); //���ֲ��ң��ҵ����ڵ���sumj�ĵ�һ������ 
//            if (it != sum.end())
//            {
//                ans = min(ans, int(it - nums.begin()) - i);//ѡ���С�ĳ���
//            }
//        }
//        return ans == n + 1 ? 0 : ans;
//    }
//    /*sum[j]-sum[i]>=target������Ŀ��������������sum[j]��Ӧnums[0:j-1]�ĺͣ�sum[i]��Ӧnums[0:i-1]�ĺ�
//    ��������õ�����i:j-1�ĺͣ����䳤�Ⱦ�Ϊj-i,��������ֻ��Ҫ�ҵ�һ��sumj����target+sum[i]����*/
//};//ǰ׺��+���ֲ���
//
//
//class Solution2{
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size();
//        int start = 0, end = 0,ans=n+1;
//        int sum = 0;
//        while (end < n)
//        {
//            sum += nums[end];
//            while (sum >= target)//�����ǰ���ڱ�Ŀ��ֵ�󣬾Ϳ��Դ���߼�С���ڣ�ֱ������С��Ŀ��ֵ
//            {
//                ans = min(ans, end - start + 1);
//                sum -= nums[start]; 
//                start++;
//            }
//            end++;
//        }
//        return ans==n+1? 0:ans;
//    }
//};//��������
//
//int main()
//{
//    vector<int>nums{ 0,1,2,3,4 };
//    Solution a;
//    cout << a.minSubArrayLen(6, nums);
//}