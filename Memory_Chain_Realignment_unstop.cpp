#include <iostream>
#include <memory>

struct Node {
    int value;
    int pos;
    std::shared_ptr<Node> next;

    Node(int v, int p) : value(v), pos(p), next(nullptr) {}
};

int calculate_sum_of_first_k(std::shared_ptr<Node> head, int k) {
    std::shared_ptr<Node> sortedHead = nullptr;
    std::shared_ptr<Node> sortedTail = nullptr;

    // Relink nodes in order by position tag from 1 to N
    for (int pos = 1; head != nullptr; ++pos) {
        std::shared_ptr<Node> prev = nullptr, curr = head, target = nullptr;

        while (curr) {
            if (curr->pos == pos) {
                target = curr;
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                target->next = nullptr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (target) {
            if (!sortedHead) {
                sortedHead = sortedTail = target;
            } else {
                sortedTail->next = target;
                sortedTail = sortedTail->next;
            }
        }
    }

    // Traverse first k nodes and compute sum
    int sum = 0;
    std::shared_ptr<Node> temp = sortedHead;
    for (int i = 0; i < k && temp; ++i) {
        sum += temp->value;
        temp = temp->next;
    }

    return sum;
}


int main() {
    int n, k;
    std::cin >> n >> k;

    std::shared_ptr<Node> head = nullptr;
    std::shared_ptr<Node> tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int v, p;
        std::cin >> v >> p;

        std::shared_ptr<Node> node = std::make_shared<Node>(v, p);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int result = calculate_sum_of_first_k(head, k);
    std::cout << result << std::endl;

    return 0;
}
