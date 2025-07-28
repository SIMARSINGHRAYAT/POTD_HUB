#include <iostream>
#include <vector>
#include <tuple>

struct Node {
    int id;
    int val;
    Node* next;

    Node(int _id, int _val) : id(_id), val(_val), next(nullptr) {}
};

std::string detect_cycle_or_sum(int n, const std::vector<std::tuple<int, int, int>>& blocks, int head_id) {
    // Step 1: Dynamically allocate nodes
    Node** memory = new Node*[n];
    for (int i = 0; i < n; ++i) {
        int bid = std::get<0>(blocks[i]);
        int val = std::get<1>(blocks[i]);
        memory[i] = new Node(bid, val);
        // Temporarily stash next_id using pointer casting
        *((int*)&memory[i]->next) = std::get<2>(blocks[i]);
    }

    // Step 2: Manually link the next pointers
    for (int i = 0; i < n; ++i) {
        int target_id = *((int*)&memory[i]->next);
        memory[i]->next = nullptr; // Default to null
        if (target_id == -1) continue;
        for (int j = 0; j < n; ++j) {
            if (memory[j]->id == target_id) {
                memory[i]->next = memory[j];
                break;
            }
        }
    }

    // Step 3: Locate the head node
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        if (memory[i]->id == head_id) {
            head = memory[i];
            break;
        }
    }

    if (!head) {
        for (int i = 0; i < n; ++i) delete memory[i];
        delete[] memory;
        return "CYCLE DETECTED";
    }

    // Step 4: Detect cycle using Floyd’s Tortoise and Hare
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            for (int i = 0; i < n; ++i) delete memory[i];
            delete[] memory;
            return "CYCLE DETECTED";
        }
    }

    // Step 5: Traverse and sum valid values
    int sum = 0;
    Node* curr = head;
    while (curr) {
        sum += curr->val;
        curr = curr->next;
    }

    for (int i = 0; i < n; ++i) delete memory[i];
    delete[] memory;
    return std::to_string(sum);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int>> blocks(n);
    for (int i = 0; i < n; ++i) {
        int bid, val, nid;
        std::cin >> bid >> val >> nid;
        blocks[i] = std::make_tuple(bid, val, nid);
    }

    int head_id;
    std::cin >> head_id;

    std::cout << detect_cycle_or_sum(n, blocks, head_id) << std::endl;
    return 0;
}
