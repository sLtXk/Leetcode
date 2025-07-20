//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    // 原地旋转矩阵90度（顺时针），不使用额外的矩阵空间
//    void rotate(vector<vector<int>>& matrix) {
//        int n = matrix.size();  // 获取矩阵的边长（n x n）
//        // 外层循环：遍历矩阵的前 n/2 行（层数）
//        // 注意：当 n 为奇数时，中间那一行不需要处理
//        for (int i = 0; i < n / 2; ++i) {
//            // 内层循环：遍历每层前半部分的列
//            // (n + 1) / 2 保证奇数矩阵时中心列也能正确处理
//            for (int j = 0; j < (n + 1) / 2; ++j) {
//                // 将当前位置的元素保存到临时变量 temp 中
//                int temp = matrix[i][j];
//
//                // 执行四个对应位置的交换：
//                // 1. 将左下角元素移到左上角
//                matrix[i][j] = matrix[n - j - 1][i];
//
//                // 2. 将右下角元素移到左下角
//                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
//
//                // 3. 将右上角元素移到右下角
//                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
//
//                // 4. 将保存的 temp（原左上角元素）移到右上角
//                matrix[j][n - i - 1] = temp;
//            }
//        }
//    }
//};
/*交换的公式怎么来的？注意到逆时针旋转后第i行元素实际上会变为倒数第i列第元素
因此映射关系为（i,j）->（j,n-i-1），同理，代入相同公式可以得到:
（j,n-i-1）->（n-i-1,n-j-1）,（n-i-1,n-j-1）->（n-j-1,i）,（n-j-1,i）->(i,j)，
由于一次交换4个元素，所以需要遍历n^2/4或者（n^2-1）/4次，根据奇偶数找到对应的行列即可*/

/*另一种思路，转置矩阵后再翻转每一行，也可以得到正确结果*/
