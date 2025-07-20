//struct ListNode {
//      int val;
//     ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
//
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right)
//    {
//        if (!head || left == right) return head;
//        int nodenum = 0;
//        ListNode* node = head;
//        ListNode* prev = nullptr;
//        ListNode* nright, * afterright;//标记right和right的后一个节点
//        while (node)
//        {
//            nodenum++;
//            if (nodenum <= right && nodenum > left)
//            {
//                if (nodenum == right)
//                {
//                    nright = node;
//                    afterright = node->next;
//                }//如果是最右端需记录下原本的下一个节点，防止丢失
//                ListNode* temp = node->next;
//                node->next = prev;
//                prev = node;
//                node = temp;
//            }//反转left和right之间的链表
//            else
//            {
//                prev = node;
//                node = node->next;
//            }
//        }
//        node = head;
//        nodenum = 0;
//        while (node)
//        {
//            ++nodenum;
//            if (left == 1 && nodenum == 1)
//            {
//                node->next = afterright;
//                return nright;//如果left是1则链表头会跑到末尾，此时应该返回真正的头nright
//            }
//            if (nodenum == left - 1) node->next = nright;//left前一节点指向right
//            else if (nodenum == right)
//            {
//                node->next = afterright;
//                break;
//            }
//            node = node->next;
//        }
//        return head;//其他情况正常返回头部
//    }
//};//自己写的
//
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        if (!head || left == right) return head;
//
//        // 创建伪头节点，处理 left = 1 的情况
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* pre = dummy;
//
//        // 1. 让 pre 指向 left 的前一个节点 (left-1)
//        for (int i = 1; i < left; i++) {
//            pre = pre->next;
//        }
//
//        // 2. 反转 left → right 之间的链表
//        ListNode* cur = pre->next;
//        ListNode* next = nullptr;
//        ListNode* prev = nullptr;
//        for (int i = left; i <= right; i++) {
//            next = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = next;
//        }//结束后pre在right的位置，cur和next都在原right+1的位置
//
//        // 3. 连接反转部分与剩余部分
//        pre->next->next = cur;  // pre->next其实还是原来的left,left和left-1的next互相指向对方，此时只需将原来的头连接到cur的位置即可
//        pre->next = prev;       // pre的下一个节点指向原来的尾，完成反转
//
//        return dummy->next;  // 伪头节点的 next 就是新的头
//    }
//};//gpt优化后