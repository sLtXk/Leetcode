#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), h = 0;
        for (int i = 0; i < n; i++)//n篇论文h指数最多是n
        {
            if (citations[i] >= n - i) h = max(h, n - i);
            else h = citations[i];
        }
    }
};