class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    Node *compute(Node *head) {
        head = reverseList(head);

        int maxi = head->data;
        Node* curr = head;

        while (curr && curr->next) {
            if (curr->next->data < maxi) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxi = curr->data;
            }
        }

        return reverseList(head);
    }
};