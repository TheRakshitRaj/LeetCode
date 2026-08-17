class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;

        Node* curr = head;

        while (curr != nullptr) {

            if (curr->child != nullptr) {

                Node* next = curr->next;

                Node* child = flatten(curr->child);
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                Node* tail = child;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                if (next != nullptr) {
                    tail->next = next;
                    next->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};