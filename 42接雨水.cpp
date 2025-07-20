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
//        vector<int>leftmax(n), rightmax(n);//记录索引i和其左侧部分的最大高度，以及i和右侧的最大高度
//        leftmax[0] = height[0];
//        rightmax[n - 1] = height[n - 1];
//        for (int i = 1; i < n; i++)
//        {
//            leftmax[i] = max(leftmax[i - 1], height[i]);//最大高度等于当前高度和之前高度中最大值
//        }
//        for (int i = n - 2; i >= 0; i--)
//        {
//            rightmax[i] = max(rightmax[i + 1], height[i]);
//        }
//        int res = 0;
//        for (int i = 0; i < n; i++)
//        {
//            res += min(leftmax[i], rightmax[i]) - height[i];//当前这一级的储水量就为两侧高度中较小的一侧，再减去当前的高度
//        }
//        return res;
//    }
//}; //动态规划
//
//class Solution2 {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        stack<int>stk;//单调栈，栈底到栈顶递减，这里不严格递减也可以，下面会解释为什么
//        int res = 0;
//        for (int i = 0; i < n; i++)
//        {
//            while (!stk.empty() && height[i] > height[stk.top()]) //如果当前高度比栈顶高，则当前索引i和top和top的前一元素left可以储水,对应左边界，谷底和右边界
//            {
//                int top = stk.top();
//                stk.pop();
//                int left = stk.top();
//                int width = i - left - 1;//能够储水的区域宽度，因为左边和右边是不储水的所以要再减1
//                int h = min(height[left], height[i])-height[top];//储水高度取决于较低的边界减去谷底的高度差
//                res += width * h;//储水的量，不严格递减也可以的原因是，如果栈中top和left高度相同，则h肯定为0，对应的储水量为0
//            }
//            stk.push(i);//比栈顶矮就推入栈中，对应非严格递减
//        }
//        return res;
//    }
//}; //单调栈
//
//class Solution3 {
//public:
//    int trap(vector<int>& height) {
//        int left = 0, right = height.size() - 1;
//        int leftmax = 0, rightmax = 0;
//        int res = 0;
//        while (left < right)
//        {
//            leftmax = max(leftmax, height[left]);//代表当前索引及左边的高度最大值
//            rightmax = max(rightmax, height[right]);//代表当前索引及右边的高度最大值
//            if (leftmax < rightmax)//由于储水量取决于较低的那一侧，因为右边最高点比左边高，因此可以直接用左侧最大值计算当前储水量
//            {
//                res += leftmax - height[left];
//                left++;
//            }
///*本质上是水的储存量取决于左右端最高点最小的一侧。因此即使我们不知道中间的部分长什么样，我们只需要保证当前左右侧最高点中，
//小的那一侧的容量得到更新就可以。我们可以通过分类讨论来分析这样的可行性，假设我们left点高度为3，left点及其左侧最高为10，
//right点高度为1，right点及其右侧最高点为5，那么我们应该更新right点的储水量：
//1. 如果right点到left点之间出现了比5更高的点，无影响，因为这个点比5高，因此储水量取决于5；
//2. 如果出现了比5还低的点，也无影响，因为这个点肯定比左侧的10低，因此储水区间仍在[10,5]这个范围内，仍是由5来计算right点储的储水量。*/
//            else
//            {
//                res += rightmax - height[right];
//                right--;
//            }//反之同理
//        }
//        return res;
//    }
//}; //双指针优化动态规划时间空间复杂度