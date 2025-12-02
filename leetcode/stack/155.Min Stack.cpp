#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    struct Node {
        int val;
        int min;
        Node* next;
    };

    Node* topNode;

    MinStack() : topNode(nullptr){};

    void push(int val) {
        Node* node = new Node;
        node->val = node->min = val;
        node->next = nullptr;

        if(!topNode) topNode = node;
        else {
            node->min = min(topNode->min, node->val);
            node->next = topNode;
            topNode = node;
        }
    }

    void pop() {
        topNode = topNode->next;

    }

    int top() {
        return topNode->val;
    }

    int getMin() {
        return topNode->min;
    }
};
