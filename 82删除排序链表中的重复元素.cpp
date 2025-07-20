//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) return head;
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* prev = dummy;
//        ListNode* curr = head;
//        ListNode* next = curr->next;
//        bool flag = 0;
//        while (next)
//        {
//            while (next && curr->val == next->val)//判断下一个元素是否为重复元素
//            {
//                next = next->next;
//                flag = 1;
//            }
//            if (flag == 1)//如果是重复元素
//            {
//                curr = next;//curr更新为重复部分的下一个
//                prev->next = next;//跳过重复的元素,prev不用更新以保证其在重复部分的前面
//                flag = 0;
//                if (next) //如果next不是最后一个就接着迭代
//                    next = next->next;//next更新为下一个节点，之后回到上面while循环继续判断
//            }
//            else
//            {
//                prev = prev->next;
//                curr = curr->next;
//                next = next->next;//如果无重复就三者同时更新
//            }
//        }
//        return dummy->next;
//    }
//};//自己写的
//
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) return nullptr;
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* prev = dummy;
//        ListNode* curr = head;
//        while (curr)
//        {
//            // 1. 发现重复元素，向前遍历找到第一个不同的元素
//            while (curr->next && curr->val == curr->next->val)
//                curr = curr->next;
//            // 2. 如果 prev 的下一个仍然是 curr，说明 curr 不是重复元素
//            if (prev->next == curr) prev = prev->next;
//            else prev->next = curr->next;
//            curr = curr->next;
//        }
//        return dummy->next;
//    }
//};//gpt优化变量版