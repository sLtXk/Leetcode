#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();//m行n列
        int flag_h = 1, flag_v = 1; // 水平与竖直方向flag
        int turn = 1;//turn为1时水平方向遍历，0时竖直方向遍历
        int count = m * n;//元素总个数
        int i = 0, j = 0;//i对应竖直方向遍历，j对应水平方向遍历
        int num_h = n, num_v = --m;//水平与竖直方向元素数量,因为行遍历完了后列不用重复遍历所以少1
        vector<int>res;
        while (count > 0)
        {
            while (turn == 1)
            {
                if (num_h==0)//遍历完当前这一行
                {
                    j -= flag_h;//j多处理了一次，会越界，所以需要往回一格
                    flag_h = -flag_h;//横向遍历方向改变
                    turn = 0;//改为竖直遍历
                    i += flag_v;//调整至竖直遍历
                    num_h=--n;//下一次进行水平遍历时少一个元素，因为在竖直遍历时已经遍历过了
                    break;
                }
                else
                {
                    res.emplace_back(matrix[i][j]);
                    j += flag_h;//这里在处理一列的最后一个元素时会超范围（因为数组索引从0开始）
                    num_h--;
                    count--;
                }
            }
            while (turn == 0)
            {
                if (num_v == 0)
                {
                    i -= flag_v;//i多处理了一次，会越界，所以需要往回一格
                    flag_v = -flag_v;//竖直遍历方向改变
                    turn = 1;//改为横向遍历
                    j += flag_h;//调整至横向遍历
                    num_v = --m;//下一次进行竖直遍历时少一个元素，因为在水平遍历时已经遍历过了
                    break;
                }
                else
                {
                    res.emplace_back(matrix[i][j]);
                    i += flag_v;
                    num_v--;
                    count--;
                }
            }
        }
        return res;
    }
};//思路与Z字形变换相似
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if (matrix.empty()) return {}; // 处理空输入
//
//        int m = matrix.size(), n = matrix[0].size();
//        int left = 0, right = n - 1, top = 0, bottom = m - 1; // 设定四个边界
//        vector<int> res;
//
//        while (left <= right && top <= bottom) {
//            // 从左到右
//            for (int j = left; j <= right; j++) res.push_back(matrix[top][j]);
//            top++; // 这一行已访问，收缩上边界
//
//            // 从上到下
//            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
//            right--; // 这一列已访问，收缩右边界
//
//            if (top <= bottom) { // 确保仍有行未访问
//                for (int j = right; j >= left; j--) res.push_back(matrix[bottom][j]);
//                bottom--; // 这一行已访问，收缩下边界
//            }
//
//            if (left <= right) { // 确保仍有列未访问
//                for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
//                left++; // 这一列已访问，收缩左边界
//            }
//        }
//        return res;
//    }
//};//gpt提供的的层层收缩思想，利用四个边界不断收缩来达到遍历效果

//int main()
//{
//    vector<vector<int>>mat = { {1,2,3},{4,5,6},{7,8,9} };
//    Solution a;
//    vector<int>res = a.spiralOrder(mat);
//    for (int b : res)
//        cout << b << " ";
//}