#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

std::string is_symmetric(Node* head) {
    if (!head || !head->next) return "YES"; // single node or empty list

    // Step 1: Find the middle using slow & fast pointers
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half from 'slow' onward
    Node* prev = nullptr;
    Node* curr = slow;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 3: Compare first half and reversed second half
    Node* left = head;
    Node* right = prev;
    while (right) {
        if (left->val != right->val) return "NO";
        left = left->next;
        right = right->next;
    }

    return "YES";
}



int main() {
    int n;
    std::cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        Node* node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    std::string result = is_symmetric(head);
    std::cout << result << std::endl;
    return 0;
}
