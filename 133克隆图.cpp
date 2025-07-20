//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//// Definition for a Node.
//class Node {
//public:
//    int val;
//    vector<Node*> neighbors;
//    Node() {
//        val = 0;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val) {
//        val = _val;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};
//class Solution {
//public:
//    unordered_map<Node*, Node*>visited;//������¼ԭ�ڵ�Ϳ�¡�Ľڵ�
//    Node* cloneGraph(Node* node) {//���ڿ�¡ԭ�ڵ�
//        if (!node) return node;
//
//        if (visited.find(node) != visited.end()) return visited[node];//�����ǰ�ڵ��Ѿ��п�¡�ڵ��ˣ�ֱ�ӷ������¡�ڵ�
//        Node* cloneNode = new Node(node->val);//�½���ǰ�ڵ�Ŀ�¡�ڵ�
//        visited[node] = cloneNode;//�����ϣ��ӳ����
//        for (auto& n : node->neighbors)//���ڵ�ǰ�ڵ���ڽӱ��еĽڵ�
//        {
//            cloneNode->neighbors.emplace_back(cloneGraph(n));
//            //��ǰ�ڵ�Ŀ�¡�ڵ���ڽӱ���Ҫ��ӵ�ǰ�ڵ���ڽӱ��нڵ�Ŀ�¡
//        }
//        return cloneNode;
//    }
//};//DFS+��ϣ��
//
//
//
//class Solution {
//public:
//    Node* cloneGraph(Node* node) {
//        if (!node) return node;
//        unordered_map<Node*, Node*>visited;//ԭ�ڵ㵽��¡�ڵ��ӳ��
//        queue<Node*>q;//��Ŵ������ԭ�ڵ�
//        q.push(node);
//        visited[node] = new Node(node->val);
//        while (!q.empty()) {
//            Node* temp = q.front(); q.pop();//ȡ�����е�ͷ�ڵ�
//            //�����ýڵ���ھ�
//            for (auto& n : temp->neighbors) {
//                if (visited.find(n) == visited.end()) {//�����ǰ�ھ�û�п�¡�ڵ�
//                    Node* cloneNode = new Node(n->val);//�½��ھӵĿ�¡�ڵ�
//                    visited[n] = cloneNode;//�����ϣ��
//                    q.push(n);
//                }
//                //�����ǰ�ھ��п�¡�ڵ㣬ֱ��������ھӵĿ�¡�ڵ㼴visited[n]�Ϳ�����
//                visited[temp]->neighbors.emplace_back(visited[n]);//��ǰ�ڵ�Ŀ�¡�ڵ���ڽӱ�������ھӵĿ�¡�ڵ�
//            }
//        }
//        return visited[node];
//    }
//};
//
