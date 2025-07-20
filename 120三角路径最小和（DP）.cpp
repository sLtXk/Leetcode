//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include<queue>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        int m = triangle.size();
//        vector<int>res = { triangle[0][0] };
//        for (int i = 1; i < m; i++)
//        {
//            res.push_back(0);
//            for (int j = i; j >= 0; j--) //必须得从右开始，因为从左开始的话res[j-1]已经被更新了，就不是上一行的结果了
//            {
//                if (j == i)//在最右端时由于补了0，且只能从左上方的点下来
//                    res[j] = triangle[i][j] + res[j - 1];//所以要用左上方结果res[j-1]+当前的值
//                else if (j == 0)
//                    res[j] += triangle[i][j];
//                else
//                    res[j] =triangle[i][j]+min(res[j],res[j-1]);
//            }
//        }
//        return *min_element(res.begin(),res.end());//用min_element直接返回最小元素
//    }
//};
//int main()
//{
//    vector<vector<int>>test = { {2},{3,4},{6,5,7} };
//    Solution a;
//    cout<< a.minimumTotal(test);
//}