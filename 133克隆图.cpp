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
//    unordered_map<Node*, Node*>visited;//用来记录原节点和克隆的节点
//    Node* cloneGraph(Node* node) {//用于克隆原节点
//        if (!node) return node;
//
//        if (visited.find(node) != visited.end()) return visited[node];//如果当前节点已经有克隆节点了，直接返回其克隆节点
//        Node* cloneNode = new Node(node->val);//新建当前节点的克隆节点
//        visited[node] = cloneNode;//存入哈希表映射中
//        for (auto& n : node->neighbors)//对于当前节点的邻接表中的节点
//        {
//            cloneNode->neighbors.emplace_back(cloneGraph(n));
//            //当前节点的克隆节点的邻接表需要添加当前节点的邻接表中节点的克隆
//        }
//        return cloneNode;
//    }
//};//DFS+哈希表
//
//
//
//class Solution {
//public:
//    Node* cloneGraph(Node* node) {
//        if (!node) return node;
//        unordered_map<Node*, Node*>visited;//原节点到克隆节点的映射
//        queue<Node*>q;//存放待处理的原节点
//        q.push(node);
//        visited[node] = new Node(node->val);
//        while (!q.empty()) {
//            Node* temp = q.front(); q.pop();//取出队列的头节点
//            //遍历该节点的邻居
//            for (auto& n : temp->neighbors) {
//                if (visited.find(n) == visited.end()) {//如果当前邻居没有克隆节点
//                    Node* cloneNode = new Node(n->val);//新建邻居的克隆节点
//                    visited[n] = cloneNode;//加入哈希表
//                    q.push(n);
//                }
//                //如果当前邻居有克隆节点，直接添加其邻居的克隆节点即visited[n]就可以了
//                visited[temp]->neighbors.emplace_back(visited[n]);//当前节点的克隆节点的邻接表加入其邻居的克隆节点
//            }
//        }
//        return visited[node];
//    }
//};
//
