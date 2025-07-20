//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<stack>
//using namespace std;
//
//class Solution1 {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        vector<int>leftmax(n), rightmax(n);//��¼����i������ಿ�ֵ����߶ȣ��Լ�i���Ҳ�����߶�
//        leftmax[0] = height[0];
//        rightmax[n - 1] = height[n - 1];
//        for (int i = 1; i < n; i++)
//        {
//            leftmax[i] = max(leftmax[i - 1], height[i]);//���߶ȵ��ڵ�ǰ�߶Ⱥ�֮ǰ�߶������ֵ
//        }
//        for (int i = n - 2; i >= 0; i--)
//        {
//            rightmax[i] = max(rightmax[i + 1], height[i]);
//        }
//        int res = 0;
//        for (int i = 0; i < n; i++)
//        {
//            res += min(leftmax[i], rightmax[i]) - height[i];//��ǰ��һ���Ĵ�ˮ����Ϊ����߶��н�С��һ�࣬�ټ�ȥ��ǰ�ĸ߶�
//        }
//        return res;
//    }
//}; //��̬�滮
//
//class Solution2 {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        stack<int>stk;//����ջ��ջ�׵�ջ���ݼ������ﲻ�ϸ�ݼ�Ҳ���ԣ���������Ϊʲô
//        int res = 0;
//        for (int i = 0; i < n; i++)
//        {
//            while (!stk.empty() && height[i] > height[stk.top()]) //�����ǰ�߶ȱ�ջ���ߣ���ǰ����i��top��top��ǰһԪ��left���Դ�ˮ,��Ӧ��߽磬�ȵ׺��ұ߽�
//            {
//                int top = stk.top();
//                stk.pop();
//                int left = stk.top();
//                int width = i - left - 1;//�ܹ���ˮ�������ȣ���Ϊ��ߺ��ұ��ǲ���ˮ������Ҫ�ټ�1
//                int h = min(height[left], height[i])-height[top];//��ˮ�߶�ȡ���ڽϵ͵ı߽��ȥ�ȵ׵ĸ߶Ȳ�
//                res += width * h;//��ˮ���������ϸ�ݼ�Ҳ���Ե�ԭ���ǣ����ջ��top��left�߶���ͬ����h�϶�Ϊ0����Ӧ�Ĵ�ˮ��Ϊ0
//            }
//            stk.push(i);//��ջ����������ջ�У���Ӧ���ϸ�ݼ�
//        }
//        return res;
//    }
//}; //����ջ
//
//class Solution3 {
//public:
//    int trap(vector<int>& height) {
//        int left = 0, right = height.size() - 1;
//        int leftmax = 0, rightmax = 0;
//        int res = 0;
//        while (left < right)
//        {
//            leftmax = max(leftmax, height[left]);//����ǰ��������ߵĸ߶����ֵ
//            rightmax = max(rightmax, height[right]);//����ǰ�������ұߵĸ߶����ֵ
//            if (leftmax < rightmax)//���ڴ�ˮ��ȡ���ڽϵ͵���һ�࣬��Ϊ�ұ���ߵ����߸ߣ���˿���ֱ����������ֵ���㵱ǰ��ˮ��
//            {
//                res += leftmax - height[left];
//                left++;
//            }
///*��������ˮ�Ĵ�����ȡ�������Ҷ���ߵ���С��һ�ࡣ��˼�ʹ���ǲ�֪���м�Ĳ��ֳ�ʲô��������ֻ��Ҫ��֤��ǰ���Ҳ���ߵ��У�
//С����һ��������õ����¾Ϳ��ԡ����ǿ���ͨ���������������������Ŀ����ԣ���������left��߶�Ϊ3��left�㼰��������Ϊ10��
//right��߶�Ϊ1��right�㼰���Ҳ���ߵ�Ϊ5����ô����Ӧ�ø���right��Ĵ�ˮ����
//1. ���right�㵽left��֮������˱�5���ߵĵ㣬��Ӱ�죬��Ϊ������5�ߣ���˴�ˮ��ȡ����5��
//2. ��������˱�5���͵ĵ㣬Ҳ��Ӱ�죬��Ϊ�����϶�������10�ͣ���˴�ˮ��������[10,5]�����Χ�ڣ�������5������right�㴢�Ĵ�ˮ����*/
//            else
//            {
//                res += rightmax - height[right];
//                right--;
//            }//��֮ͬ��
//        }
//        return res;
//    }
//}; //˫ָ���Ż���̬�滮ʱ��ռ临�Ӷ�