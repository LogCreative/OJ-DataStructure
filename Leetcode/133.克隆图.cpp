/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include<iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* new_node = new Node(node->val);
        unordered_map<int, Node*> node_map;
        queue<pair<Node*, Node*>> node_queue;
        node_queue.push({node, new_node});
        node_map[node->val] = new_node;
        while (!node_queue.empty()) {
            auto top_nodes = node_queue.front();
            node_queue.pop();
            Node* ori_node = top_nodes.first;
            Node* cpy_node = top_nodes.second;
            vector<Node*> new_neighbors;
            for (Node* neighbor : ori_node->neighbors) {
                if (node_map.count(neighbor->val)) {
                    new_neighbors.push_back(node_map[neighbor->val]);
                } else {
                    Node* new_neighbor = new Node(neighbor->val);
                    node_map[neighbor->val] = new_neighbor;
                    new_neighbors.push_back(new_neighbor);
                    node_queue.push({neighbor, new_neighbor});
                }
            }
            cpy_node->neighbors = new_neighbors;
        }
        // for (auto node : node_map) {
        //     cout << node.second->val << ": ";
        //     for (auto n : node.second->neighbors) {
        //         cout << n->val << ' ';
        //     }
        //     cout << endl;
        // }
        return new_node;
    }
};
// @lc code=end

