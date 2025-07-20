//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        if (!head || !head->next) return head;
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        int n = 1;//记录长度
//        ListNode* tail = head;//尾节点
//        while (tail->next)
//        {
//            tail = tail->next;
//            n++;
//        }
//        //由于单向链表无法从后往前遍历，因此我们将右移k位操作改为将头节点移至结尾n-k次操作
//        for (int i = 1; i <= n - k % n; i++)//处理k大于n的情况
//        {
//            tail->next = dummy->next;//将头节点移至尾部，先移保证tail能更新
//            tail = tail->next;//尾更新
//            dummy->next = dummy->next->next;//设置新的头结点
//            tail->next = nullptr;
//        }
//        return dummy->next;
//    }
//};//自己写的
//
//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        if (!head || !head->next || k == 0) return head;
//        // 计算链表长度，并找到尾节点
//        int n = 1;
//        ListNode* tail = head;
//        while (tail->next)
//        {
//            tail = tail->next;
//            n++;
//        }
//        // 处理 k 过大的情况
//        k = k % n;
//        if (k == 0) return head;
//        // 找到新头的前驱节点 (第 n - k 个节点)
//        ListNode* prev = head;
//        for (int i = 1; i < n - k; i++)
//            prev = prev->next;
//        // //标记新的头的位置
//        ListNode* newHead = prev->next;
//        prev->next = nullptr;//将新的尾节点下一节点设为空
//        tail->next = head;//直接将原来尾部连向原来的头部
//        return newHead;
//    }
//};//gpt优化指针连接