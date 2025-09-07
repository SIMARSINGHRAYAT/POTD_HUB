class Solution {
public:
    Node* mergeKLists(vector<Node*> &arr) {
        // Min heap to keep track of the smallest node
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> minHeap;

        // Add the head node of each list to the heap
        for (auto node : arr) {
            if (node) minHeap.push({node->data, node});
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!minHeap.empty()) {
            auto [val, node] = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                minHeap.push({node->next->data, node->next});
            }
        }

        return dummy->next;
    }
};
