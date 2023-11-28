/*
一个循环链表，链表中的每个节点包含一个整数int和前后指针，给一个任意指针指p1向该循环链表中的节点，
再给一个指针p2指向循环链表外的一个节点，查找该链表中是否包含p2指针指向节点的值
，若存在则返回循环链表中节点指针的地址，若不存在则返回nullptr.
*/

#include <iostream>

using namespace std;

// 节点
struct Node {
    int value;
    Node* pre;
    Node* next;
    Node(int val) :value(val), pre(nullptr), next(nullptr) {}
};

// 循环链表
class CyclicList {
public:
    Node* head;
    CyclicList():head(nullptr){}
    void addNode(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
            head->pre = head;
            head->next = head;
        }else{
            Node* lastNode = head->pre;
            lastNode->next = node;
            node->pre = lastNode;
            node->next = head;
            head->pre = node;
        }
    }
};

Node* searchNode(Node* head, Node* targetNode) {
    if (!head || !targetNode) {
        return nullptr;
    }
    Node* p = head;  // 工作指针
    do {
        if (p->value == targetNode->value) {
            return p;
        }
        p = p->next;
    } while (p != head);
    return nullptr;
}

#if 1
int main() {
    // 创建循环链表
    CyclicList cyclist;
    cyclist.addNode(1);
    cyclist.addNode(3);
    cyclist.addNode(5);
    cyclist.addNode(7);
    // 目标节点
    Node* node = new Node(1);
    Node* ans = searchNode(cyclist.head, node);
    if (ans != nullptr) {
        cout << "循环链表中存在目标节点" << node->value << ", 地址为：" << node << endl;
    }
    else {
        cout << "循环链表中不存在目标节点" << node->value << endl;
    }

    return 0;
}
#endif