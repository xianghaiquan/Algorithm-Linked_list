/*
һ��ѭ�����������е�ÿ���ڵ����һ������int��ǰ��ָ�룬��һ������ָ��ָp1���ѭ�������еĽڵ㣬
�ٸ�һ��ָ��p2ָ��ѭ���������һ���ڵ㣬���Ҹ��������Ƿ����p2ָ��ָ��ڵ��ֵ
���������򷵻�ѭ�������нڵ�ָ��ĵ�ַ�����������򷵻�nullptr.
*/

#include <iostream>

using namespace std;

// �ڵ�
struct Node {
    int value;
    Node* pre;
    Node* next;
    Node(int val) :value(val), pre(nullptr), next(nullptr) {}
};

// ѭ������
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
    Node* p = head;  // ����ָ��
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
    // ����ѭ������
    CyclicList cyclist;
    cyclist.addNode(1);
    cyclist.addNode(3);
    cyclist.addNode(5);
    cyclist.addNode(7);
    // Ŀ��ڵ�
    Node* node = new Node(1);
    Node* ans = searchNode(cyclist.head, node);
    if (ans != nullptr) {
        cout << "ѭ�������д���Ŀ��ڵ�" << node->value << ", ��ַΪ��" << node << endl;
    }
    else {
        cout << "ѭ�������в�����Ŀ��ڵ�" << node->value << endl;
    }

    return 0;
}
#endif